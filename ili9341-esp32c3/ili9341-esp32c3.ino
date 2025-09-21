#include <Arduino.h>
// #include "bb_spi_lcd.h"
// SPILCD lcd;
// #define LCD LCD_ILI9341
// #define COLOR_WHITE 0xFFFF
// #define COLOR_BLACK 0x0000

// int rc;

void setup() {
    Serial.begin(115200);
    // rc = spilcdInit(&lcd, LCD, 0, 40000000, 8, 3, -1, -1, -1, MOSI, SCK, 0);
    Serial.println("hi");

    // spilcdFill(&lcd, COLOR_WHITE, 1);

  // Set the text orientation to native portrait mode
//   spilcdSetOrientation(&lcd, 0);

//   // Write "hello" to the screen at position (x=10, y=20)
//   // spilcdWriteString(x, y, "text", FOREGROUND_COLOR, BACKGROUND_COLOR, bLargeFont);
//   spilcdWriteString(&lcd, 10, 20, "hello", COLOR_WHITE, COLOR_BLACK, 0, 0);

//   Serial.begin(115200);
//   lcd.begin(DISPLAY_CYD);
//   //lcd.rtInit(TOUCH_MOSI, TOUCH_MISO, TOUCH_CLK, TOUCH_CS); // initialize touch AFTER initializing the LCD
//   lcd.fillScreen(TFT_BLACK);
//   lcd.setTextColor(TFT_GREEN, TFT_BLACK);
//   lcd.setFont(FONT_12x16);
//   lcd.println("Test");
  //lcd.println("Clear by touching here");
}

void loop() {
    Serial.println("hi");
}
