/*
  ESP32-C3 + ILI9341 TFT LCD Example (using Franzininho WiFi)

  https://wokwi.com/projects/329115934477255250
*/

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 3
#define TFT_CS 8
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  tft.begin();

  tft.setCursor(46, 120);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(3);
  tft.println("ESP32-C3");
}

const uint32_t colors[] = {
  ILI9341_GREEN,
  ILI9341_CYAN,
  ILI9341_MAGENTA,
  ILI9341_YELLOW,
};
uint8_t colorIndex = 0;

void loop() {
  tft.setTextSize(2);
  tft.setCursor(42, 164);
  tft.setTextColor(colors[colorIndex++ % 4]);
  tft.println("SPI works :-)");
  delay(250);
}
