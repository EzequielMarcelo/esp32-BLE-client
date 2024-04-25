#include "BLEClientLibrary.h"

void BLEClientLibrary::begin()
{
    BLEDevice::init("");
    _scan = BLEDevice::getScan();
    _scan->setAdvertisedDeviceCallbacks(this);
    _scan->setInterval(1349);
    _scan->setWindow(449);
    _scan->setActiveScan(true);
    Serial.println("Scaneando...");
}
void BLEClientLibrary::StartScan()
{
    BLEDevice::getScan()->start(1);
}
void BLEClientLibrary::onResult(BLEAdvertisedDevice device)
{
    if(device.haveServiceUUID() && device.isAdvertisingService(BLEUUID(SERVICE_UUID)))
    {
        Serial.println(device.getAddress().toString().c_str());
    }
}
