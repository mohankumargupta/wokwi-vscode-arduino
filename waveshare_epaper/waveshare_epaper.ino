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
    send_command(0x12);
    delay(20);

    //sendCommand(0x01) DRIVER OUTPUT CONTROL
    send_command(0x01);
    uint8_t driver_output_data[] = {0xFF, 0x00, 0xFF};
    send_data(driver_output_data, sizeof(driver_output_data)); 

    //sendCommand(0x11) DATA ENTRY MODE
    send_command(0x11);
    uint8_t data_entry_data[] = {0x03}; 
    send_data(data_entry_data, sizeof(data_entry_data));

    //sendCommand(0x44) RAM Memory Region(x)
    send_command(0x44);
    uint8_t x_start = 0;
    uint8_t y_start = 0;
    uint8_t x_end = 128;
    uint16_t y_end = 296;
    uint8_t ram1_xdata = (x_start >> 3) & 0xFF;
    uint8_t ram2_xdata = (x_end >> 3) & 0xFF;
    uint8_t ram_xdata[2]{};
    ram_xdata[0] = ram1_xdata;
    ram_xdata[1] = ram2_xdata; 
    send_data(ram_xdata, sizeof(ram_xdata));
    
    //sendCommand(0x45) RAM Memory Region(y)
    send_command(0x45);
    uint8_t ram1_ydata = y_start & 0xFF;
    uint8_t ram2_ydata = (y_start >> 8) & 0xFF;
    uint8_t ram3_ydata = y_end & 0xFF;
    uint8_t ram4_ydata = (y_end >> 8) & 0xFF;
    uint8_t ram_ydata[4]{};
    ram_ydata[0] = ram1_ydata;
    ram_ydata[1] = ram2_ydata;
    ram_ydata[2] = ram3_ydata;
    ram_ydata[3] = ram4_ydata;
    send_data(ram_ydata, sizeof(ram_ydata));
    // x point must be the multiple of 8 or the last 3 bits will be ignored */
    /*  
    SendCommand(0x44);
    SendData((x_start >> 3) & 0xFF);
    SendData((x_end >> 3) & 0xFF);
    SendCommand(0x45);
    SendData(y_start & 0xFF);
    SendData((y_start >> 8) & 0xFF);
    SendData(y_end & 0xFF);
    SendData((y_end >> 8) & 0xFF)
    */

    //sendCommand(0x21) Display update control
    send_command(0x21);
    uint8_t display_update_data[] = {0x00, 0x80};
    send_data(display_update_data, sizeof(display_update_data));

    //sendCommand(0x4E) memory cursor
    send_command(0x4E);
    uint8_t memory_cursor_data[2] = {0x00, 0x00};
    send_data(memory_cursor_data, sizeof(memory_cursor_data));
    delay(20);
}

void loop() {

}

void spiSend(uint8_t dcLevel, const uint8_t* buffer, size_t length) {
  digitalWrite(DC_PIN, dcLevel);
  digitalWrite(SS, LOW);

  // Actually transmit
  SPI.transfer((void*)buffer, length);

  digitalWrite(SS, HIGH);
}

void send_command(const uint8_t cmd) {
  spiSend(LOW, &cmd, 1);  // DC = 0 → command
}

void send_data(const uint8_t* data, size_t length) {
  spiSend(HIGH, data, length); // DC = 1 → data
}
