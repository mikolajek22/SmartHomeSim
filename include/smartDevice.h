#include <string>
#include <iostream>
#include <cstdint>

using namespace std;
#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H
class Network {
    public:
        uint8_t ipAddr[4];
        uint8_t netMask[4];
        uint8_t defGw[4];
        uint8_t broker[4];
};


class smartDevice {
    protected:
        Network netSettings;
        string  name;
        bool    isOn;
        int     id;
    public:
        smartDevice(Network netSettings, string name, int id);
        bool changeNetSetting(Network netSetting);
        Network getNetSettings();
        bool changeName(string name);
        int getId() const;
        string getName();

        virtual bool turnOn();
        virtual bool turnOff();
        virtual bool getStatus();
        virtual ~smartDevice() = default;
};
#endif