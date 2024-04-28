#include "BLEClientLibrary.h"

void BLEClientLibrary::begin()
{
    BLEDevice::init("");
    _scan = BLEDevice::getScan();
    _scan->setAdvertisedDeviceCallbacks(this);
    _scan->setInterval(1349);
    _scan->setWindow(449);
    _scan->setActiveScan(true);
    Serial.println("Scanning...");
}
void BLEClientLibrary::StartScan()
{
    BLEScanResults foundDevices = _scan->start(1);
    Serial.print("Devices found: ");
    Serial.println(foundDevices.getCount());
    _scan->clearResults();
}
void BLEClientLibrary::onResult(BLEAdvertisedDevice device)
{
    if(device.haveServiceUUID() && device.isAdvertisingService(BLEUUID(SERVICE_UUID)))
    {
        Serial.println(device.getAddress().toString().c_str());
    }
}
