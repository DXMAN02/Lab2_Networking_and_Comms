#include <Wire.h>

#define I2C_DEV_ADDR 0x35

void onReceive(int len) {

  Serial.print("Recibidos: ");

  while (Wire.available()) {

    int c = Wire.read();

    Serial.print(c);
    Serial.print(" ");
  }

  Serial.println();
}

void setup() {

  Serial.begin(115200);

  Wire.begin((uint8_t)I2C_DEV_ADDR);

  Wire.onReceive(onReceive);

  Serial.println("Slave listo");
}

void loop() {

}