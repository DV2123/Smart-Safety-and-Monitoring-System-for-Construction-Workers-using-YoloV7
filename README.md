# Industry-Safety-Detection-using-Yolov7

## Overview

This project utilizes YOLOv7, a cutting-edge object detection model, to improve safety standards for construction workers. By detecting essential safety equipment such as helmets, gloves, reflective jackets, and protective footwear, the system ensures that workers are complying with safety regulations in real-time. The system provides immediate alerts to supervisors if any safety gear is missing, helping to reduce the risk of accidents and improve overall safety on construction sites.

## Problem Statement

Construction sites are high-risk environments where worker safety is a critical concern. Despite safety regulations and protocols, accidents still occur due to inadequate monitoring of personal protective equipment (PPE). Manual safety inspections can be slow and prone to errors, leaving room for safety violations. This project addresses the need for automated, real-time detection of PPE compliance to prevent accidents and injuries on construction sites.

## Scope of the Application

This project focuses on the detection of safety gear worn by construction workers, including helmets, gloves, reflective jackets, and protective footwear. The system will:

Automatically detect whether workers are wearing the required safety gear.
Send real-time alerts if workers are found missing critical safety equipment.
Upload detection data to a cloud database for further analysis and compliance reporting.
Provide a dashboard for supervisors to monitor multiple construction sites in real time, enhancing safety oversight.

## Tech Stack

- Python: The primary programming language for development.
- PyTorch: The deep learning framework used for model training and inference.
- AWS S3 Bucket: For data storage, digestion, and model version control.
- labelImg: The tool used for data annotation, crucial for training accurate models.
- Flask: For creating and serving the web API.

## Deployment Stack

- AWS EC2 (Elastic Compute Cloud): For deploying and hosting the web API.
- AWS ECR (Elastic Container Registry): For managing and storing Docker container images.
- Docker: For creating isolated environments and packaging the application.
- GitHub: For version control and repository hosting.
- GitHub Actions: For continuous integration and continuous deployment (CI/CD), automating the software lifecycle.

How to run?

```
git clone https://github.com/patelshehbaz/Industry-Safety-Detection-Using-YoloV7.git
```

```
conda create -n venv python=3.8 -y
```

```
conda activate venv
```

```
pip install -r requirements.txt
```

### Workflows

- constants
- config_entity
- artifact_entity
- components
- pipeline
- app.py

## License

This project is released under the MIT License. See the LICENSE file for more details.
