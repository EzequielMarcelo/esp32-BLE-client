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
        _scan->stop();
        Serial.println(device.getAddress().toString().c_str());
        _foundDevice = new BLEAdvertisedDevice(device);
    }
}
void BLEClientLibrary::onConnect(BLEClient *client)
{
    Serial.println("Sucessful connection");
}
void BLEClientLibrary::onDisconnect(BLEClient *client)
{
    Serial.println("Disconnected");
}
void BLEClientLibrary::Connect(BLEAdvertisedDevice *device)
{
    _client = BLEDevice::createClient();
    _client->setClientCallbacks(this);

    if (_client->connect(device))
    {
        BLERemoteService *remoteService = _client->getService(SERVICE_UUID);

        if (remoteService == nullptr)
        {
            Serial.println("Unrecognized service");
            Disconnect();
            _foundDevice = nullptr;
        }         
    }
    else
    {
        Serial.println("Failed to connect");
        _foundDevice = nullptr;
    } // end if
}
void BLEClientLibrary::Disconnect() 
{
    _client->disconnect();
}
bool BLEClientLibrary::isConnected()
{
    if(_client)
        return _client->isConnected();
    
    return false;
}
BLEAdvertisedDevice *BLEClientLibrary::GetFoundDevice()
{
    return _foundDevice;
}
