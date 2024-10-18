# Industry-Safety-Detection-using-Yolov7

## Overview

This project utilizes YOLOv7 for object detection to enhance safety in industrial workplaces. By automatically detecting safety gear such as helmets, gloves, jackets, and goggles on workers, the system aims to minimize the occurrence of accidents and injuries. The model's predictions help determine whether workers are equipped with appropriate safety gear, contributing to a safer work environment.

## Problem Statement

In recent decades, there's been a notable neglect in terms of safety and well-being in various industries. The practice of safety has evolved, and the safety climate is growing to safeguard all workers and improve work environments. Governments and regulatory organizations have implemented rules and laws to ensure that companies create working conditions that minimize the chances of accidents and injuries.

## Scope of the Application

The scope of this project focuses on identifying the equipment of industrial workers by detecting all safety gears such as helmets, gloves, jackets, goggles, and footwear. The system determines if the employee is having proper safety to do their work or not. The data of the detection will also be uploaded to the cloud database.

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
