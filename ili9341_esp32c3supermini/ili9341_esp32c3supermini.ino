#include <bb_spi_lcd.h>

BB_SPI_LCD lcd;

void setup() {
  Serial.begin(115200);
//   delay(1000);

lcd.begin(DISPLAY_CYD);
lcd.fillScreen(TFT_WHITE);
//   lcd.setTextColor(TFT_GREEN, TFT_BLACK);
//   lcd.setFont(FONT_12x16);
//   lcd.println("Hello");
}

void loop() {
  //delay(2000);
  //delay(200);
  Serial.println("Hello");
}
