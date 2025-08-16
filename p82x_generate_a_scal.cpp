#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// IoT Device Monitor API Specification

class IoTDevice {
public:
    string deviceId;
    string deviceName;
    string deviceType;
    string deviceStatus;

    IoTDevice(string id, string name, string type, string status) {
        deviceId = id;
        deviceName = name;
        deviceType = type;
        deviceStatus = status;
    }
};

class IoTDeviceMonitor {
private:
    unordered_map<string, IoTDevice> devices;

public:
    void addDevice(IoTDevice device) {
        devices[device.deviceId] = device;
    }

    void removeDevice(string deviceId) {
        devices.erase(deviceId);
    }

    IoTDevice getDevice(string deviceId) {
        return devices[deviceId];
    }

    vector<IoTDevice> getAllDevices() {
        vector<IoTDevice> deviceList;
        for (auto& device : devices) {
            deviceList.push_back(device.second);
        }
        return deviceList;
    }

    void updateDeviceStatus(string deviceId, string newStatus) {
        if (devices.find(deviceId) != devices.end()) {
            devices[deviceId].deviceStatus = newStatus;
        }
    }

    void printDeviceList() {
        cout << "Device List:" << endl;
        for (auto& device : devices) {
            cout << "Device ID: " << device.first << endl;
            cout << "Device Name: " << device.second.deviceName << endl;
            cout << "Device Type: " << device.second.deviceType << endl;
            cout << "Device Status: " << device.second.deviceStatus << endl;
            cout << endl;
        }
    }
};

int main() {
    IoTDeviceMonitor monitor;

    IoTDevice device1("D1", "Temperature Sensor", "Sensor", "Online");
    IoTDevice device2("D2", "Humidity Sensor", "Sensor", "Offline");
    IoTDevice device3("D3", "Security Camera", "Camera", "Online");

    monitor.addDevice(device1);
    monitor.addDevice(device2);
    monitor.addDevice(device3);

    monitor.printDeviceList();

    monitor.updateDeviceStatus("D2", "Online");

    monitor.printDeviceList();

    return 0;
}