#include <SPI.h>

#define SS_PIN 5

uint8_t write_packet[10] =
{
    0xAA,
    'W',
    0x02,
    0x02,
    0x05,
    0x09,
    0,
    0,
    0,
    0xBB
};

uint8_t sum_packet[10] =
{
    0xAA,
    'S',
    0x02,
    0x01,
    0x03,
    0,
    0,
    0,
    0,
    0xBB
};

void sendPacket(uint8_t *packet)
{
    digitalWrite(SS_PIN, LOW);

    for(int i = 0; i < 10; i++)
    {
        SPI.transfer(packet[i]);
    }

    digitalWrite(SS_PIN, HIGH);

    delay(500);
}

void setup()
{
    Serial.begin(115200);

    SPI.begin(18, 19, 23, SS_PIN);

    pinMode(SS_PIN, OUTPUT);

    digitalWrite(SS_PIN, HIGH);

    Serial.println("Master listo");

    delay(1000);

    sendPacket(write_packet);

    Serial.println("WRITE enviado");

    delay(1000);

    sendPacket(sum_packet);

    Serial.println("SUM enviado");
}

void loop()
{

}