#include <iostream>
#include <vector>
#include "smartManager.h"
#include "logger.h"

#define OCTET_NUM 4

using namespace std;

bool strIpToUint8(string strIp, uint8_t *uint8Ip) {
    for (int i = 0; i < OCTET_NUM; i++) {
        int j = 0;
        while (j < (strIp.size()) && strIp[j] != '.') {
            if (strIp[j] < '0' || strIp[j] > '9') {
                LOG_ERROR("Invalid Address");
                return false;
            }
            j++;
        }
        uint8Ip[i] = stoi(strIp.substr(0, j));
        if (j < strIp.size()) {
            strIp = strIp.substr(j + 1);
        }
    }
    return true;
}

bool setNetSettings(uint8_t* ip, uint8_t* netmask, uint8_t* defGw, uint8_t* broker) {
    string strIp, strNetmask, strDefGw, strBroker;

    LOG_INFO("Enter IP Address: ");
    cin >> strIp;
    if (!strIpToUint8(strIp, ip)) {
        return false;
    }

    LOG_INFO("Enter Netmask: ");
    cin >> strNetmask;
    if (!strIpToUint8(strNetmask, netmask)) {
        return false;
    }

    LOG_INFO("Enter Default Gateway: ");
    cin >> strDefGw;
    if (!strIpToUint8(strDefGw, defGw)) {
        return false;
    }

    LOG_INFO("Enter Broker: ");
    cin >> strBroker;
    if (!strIpToUint8(strBroker, broker)) {
        return false;
    }
    return true;
}

int main() {
    string name;
    int bubelId;
    cout << "Morgern!" << endl;
    smartManager manager;
    while (true) {
        int choice;
        LOG_INFO("********** SMART HOME **********");
        LOG_INFO("1. Add Smart Bulb");
        LOG_INFO("2. Delete Smart Bulb");
        LOG_INFO("3. Add Smart Socket");
        LOG_INFO("4. Delete Smart Socket");
        LOG_INFO("5. Add Smart Thermostat");
        LOG_INFO("6. Delete Smart Thermostat");
        LOG_INFO("7. Add Smart Thermometer");
        LOG_INFO("8. Delete Smart Thermometer");
        LOG_INFO("9. Print Smart Devices");
        LOG_INFO("0. Exit");
        LOG_INFO("********************************");
        cin >> choice;

        switch (choice) {
            case 1:
                Network netSettings;
                setNetSettings(netSettings.ipAddr, netSettings.netMask, netSettings.defGw, netSettings.broker);
                name = "b2";
                bubelId = 2;
                manager.addSmartBulb(netSettings, name, bubelId);
                cout << static_cast<int>(netSettings.ipAddr[0]) << "." <<
                    static_cast<int>(netSettings.ipAddr[1]) << "." <<
                    static_cast<int>(netSettings.ipAddr[2]) << "." <<
                    static_cast<int>(netSettings.ipAddr[3]) << endl;
                break;    
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                manager.printSmartDevices();
                break;
            default:
                break;
        }
    }
    return 0;
}