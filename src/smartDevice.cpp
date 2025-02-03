#include "smartDevice.h"

smartDevice::smartDevice(Network netSettings, string name, int id) {
        this->netSettings = netSettings;
        this->name = name;
        this->id = id;
}

bool smartDevice::changeNetSetting(Network netSetting) {
    this->netSettings = netSettings;
    return true;
}
bool smartDevice::changeName(string name) {
    this->name = name;
    return true;
}
bool smartDevice::turnOn() {
    isOn = true;
    return true;
}
bool smartDevice::turnOff() {
    isOn = false;
    return true;
}
bool smartDevice::getStatus() {
    return isOn;
}

int smartDevice::getId() const {
    return this->id;
}

string smartDevice::getName() {
    return this->name;
}