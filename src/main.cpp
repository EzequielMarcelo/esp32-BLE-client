#include <Arduino.h>
#include "BLEClientLibrary.h"

BLEClientLibrary BLE;

void setup() 
{
    Serial.begin(115200);
    BLE.begin();
}

void loop() 
{
  BLE.StartScan();
  delay(100);
}

