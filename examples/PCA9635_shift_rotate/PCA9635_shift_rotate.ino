//
//    FILE: PCA9635_shift_rotate.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo PCA9635 library
//     URL: https://github.com/RobTillaart/PCA9635


#include "Arduino.h"
#include "Wire.h"
#include "PCA9635.h"


PCA9635 ledArray(0x20);

uint8_t arr[16];  //  working array


void setup()
{
  Serial.begin(115200);
  Serial.print("PCA9635 LIB version: ");
  Serial.println(PCA9635_LIB_VERSION);
  Serial.println();

  ledArray.begin();
  //  testpulse per channel
  for (int channel = 0; channel < ledArray.channelCount(); channel++)
  {
    ledArray.setLedDriverMode(channel, PCA9635_LEDON);
    delay(200);
    ledArray.setLedDriverMode(channel, PCA9635_LEDOFF);
  }
  //  set all to PWM
  ledArray.setLedDriverMode(PCA9635_LEDPWM);


  initArray();
  ledArray.writeN(0, arr, 16);
  for (int i = 0; i < 16; i++)
  {
    delay(500);
    rotateLeft();
    ledArray.writeN(0, arr, 16);
  }
  for (int i = 0; i < 16; i++)
  {
    delay(500);
    shiftLeft(0);
    ledArray.writeN(0, arr, 16);
  }

  initArray();
  ledArray.writeN(0, arr, 16);
  for (int i = 0; i < 16; i++)
  {
    delay(500);
    rotateRight();
    ledArray.writeN(0, arr, 16);
  }
  for (int i = 0; i < 16; i++)
  {
    delay(500);
    shiftRight(0);
    ledArray.writeN(0, arr, 16);
  }
}


void loop()
{
}


void initArray()
{
  for (int i = 0; i < 16; i++)
  {
    arr[i] = i * 16 - 1;  //  0..255
  }
}

void shiftLeft(uint8_t newValue)
{
  for (int i = 0; i < 15; i++)
  {
    arr[i] = arr[i + 1];
  }
  arr[15] = newValue;
}

void shiftRight(uint8_t newValue)
{
  for (int i = 15; i > 0; i--)
  {
    arr[i] = arr[i - 1];
  }
  arr[0] = newValue;
}

void rotateLeft()
{
  shiftLeft(arr[0]);
}

void rotateRight()
{
  shiftRight(arr[15]);
}


//  -- END OF FILE --
