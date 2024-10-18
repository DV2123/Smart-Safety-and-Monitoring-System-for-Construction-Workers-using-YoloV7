#include <ESP8266WiFi.h>    // For Wi-Fi communication (or ESP32WiFi.h if using ESP32)
#include <Wire.h>           // For I2C communication
#include <Adafruit_Sensor.h> // For environmental sensors
#include <DHT.h>            // For temperature and humidity sensor

// Constants for sensors and modules
#define pulsePin A0         // Pulse sensor pin
#define DHTPIN D2           // DHT sensor pin
#define DHTTYPE DHT11       // DHT 11 temperature and humidity sensor

// Variables for sensor readings
int pulseValue = 0;
int pulseThreshold = 550;   // Adjust this threshold based on calibration
int workingFlag = 0;
float temperature = 0.0;
float humidity = 0.0;
int floorNumber = 0;

// DHT Sensor
DHT dht(DHTPIN, DHTTYPE);

// Wi-Fi Credentials
const char* ssid = "Motorolla edge 20";
const char* password = "************";

// Server to send data
const char* server = "http://****************";  // Replace with actual server

void setup() {
  Serial.begin(115200);
  
  // Initialize DHT sensor
  dht.begin();
  
  // Initialize Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  
  // Setup pulse sensor
  pinMode(pulsePin, INPUT);
  
  // Setup other sensors/modules (e.g., RFID, AQI) here
  // (Assuming RFID or Bluetooth modules are connected to different pins)
}

void loop() {
  // Get pulse sensor data
  pulseValue = analogRead(pulsePin);
  
  // Check if the worker is actively working based on pulse sensor threshold
  if (pulseValue > pulseThreshold) {
    workingFlag = 1;  // Worker is actively working
  } else {
    workingFlag = 0;  // Worker is inactive or resting
  }
  
  // Read temperature and humidity data
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  // Assume RFID or Bluetooth module sends the floor number where the worker is located
  floorNumber = getFloorNumber();  // Implement this function based on the tracking module you're using
  
  // Print data to serial monitor
  Serial.print("Pulse: ");
  Serial.print(pulseValue);
  Serial.print(" | Working: ");
  Serial.print(workingFlag);
  Serial.print(" | Temp: ");
  Serial.print(temperature);
  Serial.print("°C | Humidity: ");
  Serial.print(humidity);
  Serial.print("% | Floor: ");
  Serial.println(floorNumber);
  
  // Send data to server
  sendDataToServer(pulseValue, workingFlag, temperature, humidity, floorNumber);
  
  delay(1000);  // Delay between readings
}

// Function to simulate getting the worker's floor number (based on tracking modules)
int getFloorNumber() {
  // You would use RFID or Bluetooth data here to determine the worker's location
  // This is a placeholder function
  return random(1, 6);  // Simulate 5 floors (1 to 5)
}

// Function to send sensor data to server
void sendDataToServer(int pulse, int working, float temp, float hum, int floor) {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    
    if (client.connect(server, 80)) {
      String url = "/update?pulse=" + String(pulse) + "&working=" + String(working) +
                   "&temp=" + String(temp) + "&humidity=" + String(hum) + "&floor=" + String(floor);
      
      // Send HTTP GET request
      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                   "Host: " + server + "\r\n" +
                   "Connection: close\r\n\r\n");
      client.stop();
    }
  } else {
    Serial.println("Error: Wi-Fi not connected");
  }
}
