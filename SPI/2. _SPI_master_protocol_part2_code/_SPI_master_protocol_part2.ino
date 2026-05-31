#include <SPI.h>

#define SS_PIN 5

uint8_t packet[10] =
{
    0xAA,
    'W',
    0x03,
    0x05,
    'A',
    'B',
    'C',
    'D',
    'E',
    0xBB
};

void setup()
{
    Serial.begin(115200);

    SPI.begin(18, 19, 23, SS_PIN);

    pinMode(SS_PIN, OUTPUT);

    digitalWrite(SS_PIN, HIGH);

    Serial.println("Master listo");

    delay(1000);

    digitalWrite(SS_PIN, LOW);

    for(int i = 0; i < 10; i++)
    {
        SPI.transfer(packet[i]);
    }

    digitalWrite(SS_PIN, HIGH);

    Serial.println("Paquete enviado");
}

void loop()
{

}