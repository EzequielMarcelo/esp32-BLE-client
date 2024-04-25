#ifndef BLEClientLibrary_H_
#define BLEClientLibrary_H_

#include "Arduino.h"
#include "BLEDevice.h"

#define SERVICE_UUID "0000ffe0-0000-1000-8000-00805f9b34fb"
#define BUTTON_UUID "0000ffe1-0000-1000-8000-00805f9b34fb"

class BLEClientLibrary: public BLEAdvertisedDeviceCallbacks
{
    private:
        BLEClient *_client;
        BLEScan *_scan;
        void onResult(BLEAdvertisedDevice device);    

    public:
        void begin();
        void StartScan();
        void Connect(BLEAdvertisedDevice device);   
};

#endif
