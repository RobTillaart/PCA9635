//
//    FILE: PCA9635_OE_control.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test PCA9635 library


#include "Arduino.h"
#include "Wire.h"
#include "PCA9635.h"


PCA9635 ledArray(0x20);


void setup()
{
  Serial.begin(115200);
  Serial.print("PCA9635 LIB version: ");
  Serial.println(PCA9635_LIB_VERSION);
  Serial.println();

  ledArray.begin();

  //  just one channel
  ledArray.write1(1, 100);
  
  ledArray.setOutputEnablePin(12);
  ledArray.enableOutput(true);
  delay(1000);
  ledArray.enableOutput(false);
  delay(1000);
  ledArray.enableOutput(true);

  //  TODO  elaborate

  Serial.println("done...");
}

void loop()
{
}


// -- END OF FILE --
