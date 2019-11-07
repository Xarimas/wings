#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void sendIntData(int value);
void loop() {
  Serial.print("counter\n");
  
  Wire.requestFrom(8, 1);// request 1 bytes from Slave ID #8

  while (Wire.available()) {
    int b = Wire.read();
    sendIntData(b);
  }
  
  Wire.requestFrom(10, 1);
  
  while (Wire.available()) {
    int b = Wire.read();
    sendIntData(b);
  }
  

  delay(500);
}

// int型のデータを送信する関数
void sendIntData(int value) {
  Serial.write('H'); // ヘッダの送信
  Serial.write(lowByte(value)); // 下位バイトの送信
  Serial.write(highByte(value)); // 上位バイトの送信
    Serial.write('\n');
}
