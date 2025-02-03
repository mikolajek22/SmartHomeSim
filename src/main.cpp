#include <iostream>
#include <vector>
#include "smartManager.h"
#include "logger.h"
#include <algorithm>

#define OCTET_NUM       4

#define END_APP         0
#define BULB_ADD        1
#define BULB_RMV        2
#define SOCKET_ADD      3
#define SOCKET_RMV      4
#define THERMOMETER_ADD 5
#define THERMOMETER_RMV 6
#define THERMOSTAT_ADD  7
#define THERMOSTAT_RMV  8
#define PRINT_DEVS      9
using namespace std;

vector<int> devicesId;

/*
* @brief Calculate the device ID from the existing devices
*
*/
int calculateDevId() {
    int id = 0;
    bool found = false;
    if (devicesId.size() == 0) {
        return id;
    }
    else {
        do{
            for (int i = 0; i < devicesId.size(); i++) {
                if (devicesId[i] == id) {
                    id++;
                    break;
                }
                else if(i == devicesId.size() - 1) {
                    found = true;
                }
            }
        } while (!found);
    }
    
    return id;
}


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
    int uID;
    Network netSettings;
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
            case END_APP:
                return 0;
                break; 

            case BULB_ADD:
                if (setNetSettings(netSettings.ipAddr, netSettings.netMask, netSettings.defGw, netSettings.broker)) {
                    name = "bulb";
                    uID = calculateDevId();
                    if (uID == manager.addSmartBulb(netSettings, name, uID)) {
                        devicesId.push_back(uID);
                        LOG_INFO("Smart Bulb added successfully");
                    }
                    else {
                        LOG_ERROR("Failed to add Smart Bulb");
                    }
                }
                else {
                    LOG_ERROR("At least one of addresses is invalid");
                }
                break;    
            case BULB_RMV:
                cout << "Enter Bulb ID: " << endl;
                cin >> uID;

                if (uID == manager.deleteSmartBulb(uID)) {
                    devicesId.erase(find(devicesId.begin(), devicesId.end(), uID));
                }
                else {
                    LOG_ERROR("Invalid bubble ID");
                }
                break;

            case SOCKET_ADD:
                if (setNetSettings(netSettings.ipAddr, netSettings.netMask, netSettings.defGw, netSettings.broker)) {
                    name = "socket";
                    uID = calculateDevId();
                    if (uID == manager.addSmartSocket(netSettings, name, uID)) {
                        devicesId.push_back(uID);
                        LOG_INFO("Smart Socket added successfully");
                    }
                    else {
                        LOG_ERROR("Failed to add Smart Socket");
                    }
                }
                else {
                    LOG_ERROR("At least one of addresses is invalid");
                }
                break;
            case SOCKET_RMV:
                cout << "Enter Socket ID: " << endl;
                cin >> uID;

                if (uID == manager.deleteSmartSocket(uID)) {
                    devicesId.erase(find(devicesId.begin(), devicesId.end(), uID));
                }
                else {
                    LOG_ERROR("Invalid socket ID");
                }
                break;

            case THERMOMETER_ADD:
                if (setNetSettings(netSettings.ipAddr, netSettings.netMask, netSettings.defGw, netSettings.broker)) {
                    name = "thermometer";
                    uID = calculateDevId();
                    if (uID == manager.addSmartThermometer(netSettings, name, uID)) {
                        devicesId.push_back(uID);
                        LOG_INFO("Smart Thermometer added successfully");
                    }
                    else {
                        LOG_ERROR("Failed to add Smart Thermometer");
                    }
                }
                else {
                    LOG_ERROR("At least one of addresses is invalid");
                }
                break;
            case THERMOMETER_RMV:
                cout << "Enter Thermometer ID: " << endl;
                cin >> uID;

                if (uID == manager.deleteSmartThermometer(uID)) {
                    devicesId.erase(find(devicesId.begin(), devicesId.end(), uID));
                }
                else {
                    LOG_ERROR("Invalid thermometer ID");
                }
                break;


            case THERMOSTAT_ADD:
                if (setNetSettings(netSettings.ipAddr, netSettings.netMask, netSettings.defGw, netSettings.broker)) {
                    name = "thermostat";
                    uID = calculateDevId();
                    if (uID == manager.addSmartThermostat(netSettings, name, uID)) {
                        devicesId.push_back(uID);
                        LOG_INFO("Smart Thermostat added successfully");
                    }
                    else {
                        LOG_ERROR("Failed to add Smart Thermostat");
                    }
                }
                else {
                    LOG_ERROR("At least one of addresses is invalid");
                }
                break;
            case THERMOSTAT_RMV:
                cout << "Enter Thermostat ID: " << endl;
                cin >> uID;

                if (uID == manager.deleteSmartThermostat(uID)) {
                    devicesId.erase(find(devicesId.begin(), devicesId.end(), uID));
                }
                else {
                    LOG_ERROR("Invalid thermostat ID");
                }
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