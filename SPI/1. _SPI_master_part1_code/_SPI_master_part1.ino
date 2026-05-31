#include <SPI.h>

#define SS_PIN 5

uint8_t tx_buf[5] = {'A', 'B', 'C', 'D', 'E'};
uint8_t rx_buf[5];

void setup()
{
    Serial.begin(115200);

    SPI.begin(18, 19, 23, SS_PIN);

    pinMode(SS_PIN, OUTPUT);

    digitalWrite(SS_PIN, HIGH);

    Serial.println("SPI Master listo");
}

void loop()
{
    digitalWrite(SS_PIN, LOW);

    for(int i = 0; i < 5; i++)
    {
        rx_buf[i] = SPI.transfer(tx_buf[i]);
    }

    digitalWrite(SS_PIN, HIGH);

    Serial.print("Recibido del slave: ");

    for(int i = 0; i < 5; i++)
    {
        Serial.print((char)rx_buf[i]);
        Serial.print(" ");
    }

    Serial.println();

    delay(1000);
}