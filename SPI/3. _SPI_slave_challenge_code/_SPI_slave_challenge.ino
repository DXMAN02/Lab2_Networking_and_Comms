#include <ESP32SPISlave.h>

ESP32SPISlave slave;

uint8_t memory[32];

static constexpr size_t BUFFER_SIZE = 10;

uint8_t tx_buf[BUFFER_SIZE] = {0};

uint8_t rx_buf[BUFFER_SIZE];

void printMemory()
{
    Serial.println("MEMORIA:");

    for(int i = 0; i < 32; i++)
    {
        Serial.print("0x");

        if(i < 16) Serial.print("0");

        Serial.print(i, HEX);

        Serial.print(": ");

        Serial.println(memory[i], HEX);
    }

    Serial.println();
}

void setup()
{
    Serial.begin(115200);

    slave.setDataMode(SPI_MODE0);

    slave.begin(HSPI, 18, 19, 23, 5);

    for(int i = 0; i < 32; i++)
    {
        memory[i] = 0;
    }

    Serial.println("SPI Slave memoria listo");

    printMemory();
}

void loop()
{
    slave.transfer(tx_buf, rx_buf, BUFFER_SIZE);

    Serial.println("Paquete recibido:");

    for(int i = 0; i < BUFFER_SIZE; i++)
    {
        Serial.print("0x");
        Serial.print(rx_buf[i], HEX);
        Serial.print(" ");
    }

    Serial.println();

    if(rx_buf[0] == 0xAA && rx_buf[9] == 0xBB)
    {
        if(rx_buf[1] == 'W')
        {
            uint8_t address = rx_buf[2];

            uint8_t size = rx_buf[3];

            for(int i = 0; i < size; i++)
            {
                memory[address + i] = rx_buf[4 + i];
            }

            Serial.println("WRITE recibido");

            printMemory();
        }

        else if(rx_buf[1] == 'S')
        {
            uint8_t addr1 = rx_buf[2];

            uint8_t addr2 = rx_buf[4];

            memory[addr1] =
            memory[addr1] + memory[addr2];

            Serial.println("SUM comando recibido");

            printMemory();
        }
    }

    delay(100);
}