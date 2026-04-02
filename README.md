# ArduinoIde-RP2350-GEEK
How to get RP2350-GEEK with LCD working in Arduino IDE

1. Install RP2040 by Earle Philhower from [https://github.com/earlephilhower/arduino-pico](https://github.com/earlephilhower/arduino-pico?tab=readme-ov-file#installation)

2. Select board to "Generic RP2350"

3. Select Flash size to 16MB

4. In library manager search "TFT_espi" and install library from "Bodmer"

5. Go to your arduino library folder and find TFT_eSPI folder

6. Overwrite User_Setup.h with [User_Setup.h from this repo](./User_Setup.h)

7. At setup we need to set SPI to use correct pins, enable backlight, and set rotation to 1 (Landscape)

```
  // Set SPI to correct pins
  SPI1.setSCK(TFT_SCLK);
  SPI1.setTX(TFT_MOSI);

  // Init the tft library
  tft.begin();

  // Enable the backlight
  analogWrite(TFT_BL, 255);

  // Set correct rotation
  tft.setRotation(1);  // Landscape (Portrait + 90)
``` 

In folder [RP2350-Demo](./RP2350-Demo/) you can find demo project and UF2 file in [Releases](https://github.com/matej2005/ArduinoIde-RP2350-GEEK/releases)