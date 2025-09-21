#include <Arduino.h>
#include <SPI.h>

#define BUSY_PIN 4
#define RESET_PIN 21
#define DC_PIN 22

// SPI.begin();
// SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));

void setup() {
    pinMode(SS, OUTPUT);
    SPI.begin(SCK, -1, MOSI, SS);
    pinMode(BUSY_PIN, INPUT);
    pinMode(RESET_PIN, OUTPUT);
    pinMode(DC_PIN, OUTPUT);
    
    //hardware reset
    digitalWrite(RESET_PIN, HIGH);
    delayMicroseconds(10000);
    digitalWrite(RESET_PIN, LOW);
    delayMicroseconds(2000);
    digitalWrite(RESET_PIN, HIGH);
    delay(200);

    //sendCommand(0x12) SWRESET
    digitalWrite(DC_PIN, LOW);
    delay(100);

    //sendCommand

}

void spiSend(uint8_t dcLevel, const uint8_t* buffer, size_t length) {
  digitalWrite(DC_PIN, dcLevel);
  digitalWrite(SS, LOW);

  // Actually transmit
  SPI.transfer((void*)buffer, length);

  digitalWrite(SS, HIGH);
}

void send_command(const uint8_t* cmd, size_t length) {
  spiSend(LOW, cmd, length);  // DC = 0 → command
}

void send_data(const uint8_t* data, size_t length) {
  spiSend(HIGH, data, length); // DC = 1 → data
}
