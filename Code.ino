#include <Servo.h>

Servo s1, s2, s3, s4; 
// Định nghĩa chân cắm 
const int enc1A = 2; const int enc1B = 3; 
const int enc2A = 4; const int enc2B = 5; 
const int enc3A = 7; const int enc3B = 8; 
const int buttonPin = A0; 

// Biến lưu trữ giá trị Encoder 
volatile int angle1 = 0; 
volatile int angle2 = 0; 
volatile int angle3 = 0; // Dải: -92 đến 88 

int lastAngle1, lastAngle2, lastAngle3; 
int last2A, last3A, lastBtn = HIGH; 
bool s4State = false; 

unsigned long lastSerialTime = 0; 

void setup() { 
  Serial.begin(115200);  

  // SỬ DỤNG INPUT_PULLUP: Kích hoạt điện trở kéo lên bên trong Arduino
  // Bạn chỉ cần nối 1 chân nút nhấn vào A0, chân còn lại nối vào GND.
  pinMode(enc1A, INPUT_PULLUP); pinMode(enc1B, INPUT_PULLUP); 
  pinMode(enc2A, INPUT_PULLUP); pinMode(enc2B, INPUT_PULLUP); 
  pinMode(enc3A, INPUT_PULLUP); pinMode(enc3B, INPUT_PULLUP); 
  pinMode(buttonPin, INPUT_PULLUP); 

  // Cấu hình Servo 
  s1.attach(9);                    
  s2.attach(10, 500, 2500);       // LD-1501 dùng dải xung rộng 
  s3.attach(11);                   
  s4.attach(6);                    

  // Ngắt cho Encoder 1 (Chân 2) 
  attachInterrupt(digitalPinToInterrupt(enc1A), readEnc1, CHANGE); 

  last2A = digitalRead(enc2A); 
  last3A = digitalRead(enc3A); 

  s1.write(0); s2.write(0); s3.write(0); s4.write(0); 
   
  Serial.println(F("=== HE THONG SAN SANG ===")); 
} 

void loop() { 
  // --- Đọc Encoder 2 (Servo 2) --- 
  int curr2A = digitalRead(enc2A); 
  if (curr2A != last2A) { 
    if (digitalRead(enc2B) != curr2A) angle2++; else angle2--; 
    angle2 = constrain(angle2, 0, 180); 
    last2A = curr2A; 
  } 

  // --- Đọc Encoder 3 (Servo 3) --- 
  int curr3A = digitalRead(enc3A); 
  if (curr3A != last3A) { 
    if (digitalRead(enc3B) != curr3A) angle3++; else angle3--; 
    angle3 = constrain(angle3, -92, 88);  
    last3A = curr3A; 
  } 

  // --- Xuất lệnh cho Servo --- 
  if(angle1 != lastAngle1) s1.write(angle1); 
  if(angle2 != lastAngle2) s2.write(angle2); 
   
  int s3Pos = map(angle3, -92, 88, 0, 180); 
  if(angle3 != lastAngle3) s3.write(s3Pos); 

  // --- Nút nhấn (Dùng điện trở kéo lên nội) --- 
  int btn = digitalRead(buttonPin); 
  if (btn == LOW && lastBtn == HIGH) { // Nhấn nút là mức LOW
    delay(20); // Chống rung
    if(digitalRead(buttonPin) == LOW) { 
      s4State = !s4State; 
      int s4Angle = s4State ? 80 : 0; 
      s4.write(s4Angle); 
      Serial.print(F(">>> BUTTON: Servo 4 -> "));  
      Serial.println(s4Angle); 
    } 
  } 
  lastBtn = btn; 

  // --- HIỂN THỊ DỮ LIỆU (Mỗi 150ms) --- 
  if (millis() - lastSerialTime > 150) { 
    if (angle1 != lastAngle1 || angle2 != lastAngle2 || angle3 != lastAngle3) { 
      Serial.print(F("S1: ")); Serial.print(angle1);  
      Serial.print(F(" | S2: ")); Serial.print(angle2); 
      Serial.print(F(" | S3: ")); Serial.println(s3Pos); 
      
      lastAngle1 = angle1; 
      lastAngle2 = angle2; 
      lastAngle3 = angle3; 
    } 
    lastSerialTime = millis(); 
  } 
} 

void readEnc1() { 
  if (digitalRead(enc1A) == digitalRead(enc1B)) angle1++; 
  else angle1--; 
  angle1 = constrain(angle1, 0, 180); 
}