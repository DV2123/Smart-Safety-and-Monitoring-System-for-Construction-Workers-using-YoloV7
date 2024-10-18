Construction-Worker-Safety-Detection-using-YOLOv7
Overview
This project utilizes YOLOv7, a cutting-edge object detection model, to improve safety standards for construction workers. By detecting essential safety equipment such as helmets, gloves, reflective jackets, and protective footwear, the system ensures that workers are complying with safety regulations in real-time. The system provides immediate alerts to supervisors if any safety gear is missing, helping to reduce the risk of accidents and improve overall safety on construction sites.

Problem Statement
Construction sites are high-risk environments where worker safety is a critical concern. Despite safety regulations and protocols, accidents still occur due to inadequate monitoring of personal protective equipment (PPE). Manual safety inspections can be slow and prone to errors, leaving room for safety violations. This project addresses the need for automated, real-time detection of PPE compliance to prevent accidents and injuries on construction sites.

Scope of the Application
This project focuses on the detection of safety gear worn by construction workers, including helmets, gloves, reflective jackets, and protective footwear. The system will:

Automatically detect whether workers are wearing the required safety gear.
Send real-time alerts if workers are found missing critical safety equipment.
Upload detection data to a cloud database for further analysis and compliance reporting.
Provide a dashboard for supervisors to monitor multiple construction sites in real time, enhancing safety oversight.
Tech Stack
Python: Main programming language for the project.
PyTorch: Used for training and running inferences with the YOLOv7 model.
AWS S3 Bucket: Cloud storage solution for data and model management.
labelImg: Tool for creating annotated datasets for model training.
Flask: Web framework used to build the API for deploying the detection system.
Deployment Stack
AWS EC2: Used for hosting the safety detection system.
AWS ECR: Stores Docker images used for deployment.
Docker: Ensures the application runs in consistent environments.
GitHub: Manages the project's source code and version control.
GitHub Actions: Provides continuous integration and deployment capabilities.
How to Run
Follow these steps to set up and run the project:

Clone the repository:

bash
Copy code
git clone https://github.com/patelshehbaz/Industry-Safety-Detection-Using-YoloV7.git
Create and activate a Python virtual environment:

bash
Copy code
conda create -n venv python=3.8 -y
conda activate venv
Install the required dependencies:

bash
Copy code
pip install -r requirements.txt
Start the Flask app:

bash
Copy code
python app.py
Project Workflows
constants: Stores constant variables used across the project.
config_entity: Manages configurations for easy setup.
artifact_entity: Handles output artifacts during model training and deployment.
components: Core components for model training, inference, and evaluation.
pipeline: Manages the end-to-end process of detection, training, and validation.
app.py: The main file that runs the Flask API to serve the detection model.
