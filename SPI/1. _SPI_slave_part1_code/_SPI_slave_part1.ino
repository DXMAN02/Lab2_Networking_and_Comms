#include <ESP32SPISlave.h>

ESP32SPISlave slave;

static constexpr size_t BUFFER_SIZE = 5;
static constexpr size_t QUEUE_SIZE = 1;

uint8_t tx_buf[BUFFER_SIZE] {'1', '2', '3', '4', '5'};
uint8_t rx_buf[BUFFER_SIZE];

void setup()
{
    Serial.begin(115200);

    delay(2000);

    slave.setDataMode(SPI_MODE0);
    slave.setQueueSize(QUEUE_SIZE);

    slave.begin(HSPI, 18, 19, 23, 5);

    Serial.println("SPI Slave listo");
}

void loop()
{
    slave.transfer(tx_buf, rx_buf, BUFFER_SIZE);

    Serial.print("Recibido del master: ");

    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        Serial.print((char)rx_buf[i]);
        Serial.print(" ");
    }

    Serial.println();

    delay(100);
}