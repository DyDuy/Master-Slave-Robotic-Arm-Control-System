# Master-Slave Robotic Arm System

A real-time teleoperation robotic system designed and implemented using **Arduino Uno**, **Incremental Encoders**, and **High-Torque Servos**. [cite_start]This project demonstrates the "Master-Slave" control principle where a human operator controls a slave robot through a manual master interface[cite: 40, 43].

## 📝 Project Overview
[cite_start]This project was developed for the **Robot Technology and Applications** course at the University of Science, VNU-HCM[cite: 1, 8]. [cite_start]The system allows an operator to control a robotic arm intuitively from a distance, making it suitable for hazardous environments or industrial skill training[cite: 40, 41].

## ✨ Key Features
* [cite_start]**Intuitive Teleoperation:** The Slave arm precisely replicates the movements recorded by the Master device (joystick or simulated arm) in real-time[cite: 46, 48].
* [cite_start]**Advanced Gripper Design:** Features an improved gripper with curved fingers and protective barriers to securely hold objects and prevent slipping[cite: 255, 268].
* [cite_start]**Rack and Pinion Mechanism:** Utilizes a specialized mechanical structure to convert the SG90 servo's rotation into linear motion for the gripper's opening and closing actions[cite: 256, 266].
* [cite_start]**High-Torque Performance:** Equipped with the HiWonder LD-1501 digital servo at high-stress joints to ensure lifting capacity and stability[cite: 169].

## 🛠 Hardware & Components
* [cite_start]**Microcontroller:** Arduino Uno R3 (SMD)[cite: 51, 52].
* [cite_start]**Master Sensors:** 600 pulses/rev Incremental Encoders (2-phase AB)[cite: 105].
* **Slave Actuators:**
    * [cite_start]**High-Stress Joint:** HiWonder LD-1501 Digital RC Servo (17kg.cm)[cite: 142, 160].
    * [cite_start]**Movement Joints:** MG995 Servos[cite: 118].
    * [cite_start]**Gripper Control:** SG90 Servo[cite: 170].
* [cite_start]**Power & Connectivity:** Breadboard, male headers for stable signals, and shared GND configuration[cite: 201, 247].

## 📂 System Architecture
[cite_start]The system captures encoder pulses at the Master station, processes the logic via Arduino, and maps the values to PWM signals for the Slave servos[cite: 47, 351].
* [cite_start]**Master Input:** Encoder phases connected to digital pins D2 through D8[cite: 223, 234].
* [cite_start]**Slave Output:** Servos connected to digital pins D6, D9, D10, and D11[cite: 220, 236].

## ✅ Experimental Results & Evaluation
* [cite_start]**Performance:** The system operates stably, with the gripper successfully executing grab-and-release cycles for objects like small balls[cite: 277, 283].
* [cite_start]**Accuracy:** The use of hardware debouncing and shared ground ensures low-latency motion replication[cite: 201, 247].
* [cite_start]**Areas for Improvement:** Noted minor base vibrations during rapid rotation and voltage drops during simultaneous multi-motor operation[cite: 278, 279].

## 🔗 Project Demo & Deliverables
Below are the links to the project's visual results and source materials:

* **Video Demonstration:**https://drive.google.com/drive/folders/1xLXhC-gNvBJkIGRZS8W3qze1D7Q01DCn
* **Mechanical Design (3D Models):** [Insert your SolidWorks/CAD link here]
* **Source Code:** [Available in the `/src` folder of this repository]

---
[cite_start]**Author:** Cao Khánh Duy (Student ID: 22130040) [cite: 14, 15]  
[cite_start]**Supervisor:** Dr. Nguyễn Đăng Duy [cite: 12]  
[cite_start]**Institution:** University of Science, VNU-HCM [cite: 1]
