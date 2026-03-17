# Master-Slave Robotic Arm System

A real-time teleoperation robotic system designed and implemented using **Arduino Uno**, **Incremental Encoders**, and **High-Torque Servos**.This project demonstrates the "Master-Slave" control principle where a human operator controls a slave robot through a manual master interface.

## 📝 Project Overview
This project was developed for the **Robot Technology and Applications** course at the University of Science, VNU-HCM.The system allows an operator to control a robotic arm intuitively from a distance, making it suitable for hazardous environments or industrial skill training.

## ✨ Key Features
* **Intuitive Teleoperation:** The Slave arm precisely replicates the movements recorded by the Master device (joystick or simulated arm) in real-time.
* **Advanced Gripper Design:** Features an improved gripper with curved fingers and protective barriers to securely hold objects and prevent slipping.
* **Rack and Pinion Mechanism:** Utilizes a specialized mechanical structure to convert the SG90 servo's rotation into linear motion for the gripper's opening and closing actions.
* **High-Torque Performance:** Equipped with the HiWonder LD-1501 digital servo at high-stress joints to ensure lifting capacity and stability.

## 🛠 Hardware & Components
* **Microcontroller:** Arduino Uno R3 (SMD).
* **Master Sensors:** 600 pulses/rev Incremental Encoders (2-phase AB).
* **Slave Actuators:**
    ***High-Stress Joint:** HiWonder LD-1501 Digital RC Servo (17kg.cm).
    * **Movement Joints:** MG995 Servos.
    ***Gripper Control:** SG90 Servo.
* **Power & Connectivity:** Breadboard, male headers for stable signals, and shared GND configuration.

## 📂 System Architecture
The system captures encoder pulses at the Master station, processes the logic via Arduino, and maps the values to PWM signals for the Slave servos.
* **Master Input:** Encoder phases connected to digital pins D2 through D8.
* **Slave Output:** Servos connected to digital pins D6, D9, D10, and D11.

## ✅ Experimental Results & Evaluation
* **Performance:** The system operates stably, with the gripper successfully executing grab-and-release cycles for objects like small balls.
* **Accuracy:** The use of hardware debouncing and shared ground ensures low-latency motion replication.
* **Areas for Improvement:** Noted minor base vibrations during rapid rotation and voltage drops during simultaneous multi-motor operation.

## 🔗 Project Demo & Deliverables
Below are the links to the project's visual results and source materials:
* **Video Demonstration:**https://drive.google.com/drive/folders/1xLXhC-gNvBJkIGRZS8W3qze1D7Q01DCn
---
**Author:** Cao Khánh Duy (Student ID: 22130040).
