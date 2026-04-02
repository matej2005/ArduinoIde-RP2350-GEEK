#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

unsigned int counter;

void setup() {
  // Set SPI to correct pins
  SPI1.setSCK(TFT_SCLK);
  SPI1.setTX(TFT_MOSI);

  // Init the tft library
  tft.begin();

  // Enable the backlight
  analogWrite(TFT_BL, 255);

  // Set correct rotation
  tft.setRotation(1);  // Landscape (Portrait + 90)

  tft.fillScreen(TFT_BLACK);  // Fill screen with black
  tft.setTextSize(2);

  tft.drawString("RP2030-GEEK demo", 0, 0);

  tft.drawString("Counter: " + (String)counter, 0, 16);

  tft.drawCircle(70, 75, 40, TFT_RED);
}

void loop() {
  if (BOOTSEL) {
    // Wait for BOOT button to be relased
    while (BOOTSEL) {
      delay(1);
    }

    // Increase counter by one
    counter++;

    // Erase everything from last drawString
    tft.fillRect(0, 16, TFT_HEIGHT, 16, TFT_BLACK);

    // Print something on screen
    tft.drawString("Counter: " + (String)counter, 0, 16);
  }
}
