#include "smartManager.h"
#include <algorithm>
#include "logger.h"
/* SMART BULB*/
int smartManager::addSmartBulb(Network netSettings, string name, int id) {
    if (id < 0 || true == checkDevId(id)) {
        smartBulb *bulb = new smartBulb(netSettings, name, id);
        smartBulbs.push_back(bulb);
        smartBulbsNum++;
        return id;
    }
    else {
        return -1;
    } 
}
int smartManager::deleteSmartBulb(int id) {
    if (id < 0 || true == checkDevId(id)) {
        auto it = find_if(smartBulbs.begin(), smartBulbs.end(),[id](const smartBulb* b) {return (b->getId() == id);} );
        if (it != smartBulbs.end()) {
            smartBulbs.erase(it);
        }
        else {
            return -1;
        }
        smartBulbsNum--;
        return id;
    }
    else {
        return -1;
    }
}

/* SMART SOCKET*/
int smartManager::addSmartSocket(Network netSettings, string name, int id) {
    if (id < 0 || true == checkDevId(id)) {
        smartSocket *socket = new smartSocket(netSettings, name, id);
        smartSockets.push_back(socket);
        smartSocketsNum++;
        return id;
    }
    else {
        return -1;
    }     
}
int smartManager::deleteSmartSocket(int id) {
    if (id < 0 || true == checkDevId(id)) {
        auto it = find_if(smartSockets.begin(), smartSockets.end(),[id](const smartSocket* s) {return s->getId() == id;} );
        if (it != smartSockets.end()) {
            smartSockets.erase(it);
        }
        else {
            return -1;
        }
        smartSocketsNum--;
        return id;
    }
    else {
        return -1;
    }
}

/* SMART THERMOSTAT */
int smartManager::addSmartThermostat(Network netSettings, string name, int id) {
    if (id < 0 || true == checkDevId(id)) {
        smartThermostat *thermostat = new smartThermostat(netSettings, name, id);
        smartThermostats.push_back(thermostat);
        smartThermostatsNum++;
        return id;
    }
    else {
        return -1;
    }
}
int smartManager::deleteSmartThermostat(int id) {
    if (id < 0 || true == checkDevId(id)) {
        auto it = find_if(smartThermostats.begin(), smartThermostats.end(),[id](const smartThermostat* t) {return t->getId() == id;} );
        if (it != smartThermostats.end()) {
            smartThermostats.erase(it);
        }
        else {
            return -1;
        }
        smartThermostatsNum--;
        return id;
    }
    else {
        return -1;
    }
}
int smartManager::addSmartThermometer(Network netSettings, string name, int id) {
    if (id < 0 || true == checkDevId(id)) {
        smartThermometer *thermometer = new smartThermometer(netSettings, name, id);
        smartThermometers.push_back(thermometer);
        smartThermometersNum++;
        return id;
    }
    else {
        return -1;
    }
}
int smartManager::deleteSmartThermometer(int id) {
    if (id < 0 || true == checkDevId(id)) {
        auto it = find_if(smartThermometers.begin(), smartThermometers.end(),[id](const smartThermometer* t) {return t->getId() == id;} );
        if (it != smartThermometers.end()) {
            smartThermometers.erase(it);
        }
        else {
            return -1;
        }
        smartThermometersNum--;
        return id;
    }
    else {
        return -1;
    }
}

bool smartManager::checkDevId(int id) {
    for (int i = 0; this->deviceIds.size(); i++) {
        deviceIds[i] == id;
        return false;
    }
    return true;
}

void smartManager::printSmartDevices() {
    LOG_INFO("Smart Bulbs: ");
    for (int i = 0; i < smartBulbsNum; i++) {
        LOG_INFO("Name: " + smartBulbs[i]->getName() + " ID: " + to_string(smartBulbs[i]->getId()));
    }
    LOG_INFO("Smart Sockets: ");
    for (int i = 0; i < smartSocketsNum; i++) {
        LOG_INFO("Name: " + smartSockets[i]->getName() + " ID: " + to_string(smartSockets[i]->getId()));
    }
    LOG_INFO("Smart Thermostats: ");
    for (int i = 0; i < smartThermostatsNum; i++) {
        LOG_INFO("Name: " + smartThermostats[i]->getName() + " ID: " + to_string(smartThermostats[i]->getId()));
    }
    LOG_INFO("Smart Thermometers: ");
    for (int i = 0; i < smartThermometersNum; i++) {
        LOG_INFO("Name: " + smartThermometers[i]->getName() + " ID: " + to_string(smartThermometers[i]->getId()));
    }
}