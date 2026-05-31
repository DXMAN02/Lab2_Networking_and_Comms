#include <Wire.h>

#define SDA_PIN 21
#define SCL_PIN 22

void setup() {

  Serial.begin(115200);

  Wire.begin(SDA_PIN, SCL_PIN);

  delay(2000);

  Serial.println("Enviando...");

  Wire.beginTransmission(0x35);

  Wire.write(10);
  


  byte error = Wire.endTransmission();

  Serial.print("Resultado: ");
  Serial.println(error);
}

void loop() {

}