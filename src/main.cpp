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
  if(!BLE.isConnected() && BLE.GetFoundDevice())
      BLE.Connect(BLE.GetFoundDevice());

  else if(!BLE.GetFoundDevice())
    BLE.StartScan();
  
  delay(100);
}

