#include <Arduino.h>
#include "BLEClientLibrary.h"

#define LED 2

BLEClientLibrary BLE;

void ClickButton();

void setup() 
{
    Serial.begin(115200);
    BLE.begin(&ClickButton);
    pinMode(LED, OUTPUT);
}

void loop() 
{  
  if(!BLE.isConnected() && BLE.GetFoundDevice())
      BLE.Connect(BLE.GetFoundDevice());

  else if(!BLE.GetFoundDevice())
    BLE.StartScan();
  
  delay(100);
}
void ClickButton()
{
  digitalWrite(LED, !digitalRead(LED));
}

