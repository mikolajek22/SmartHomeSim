#include "smartThermostat.h"
#include "smartThermometer.h"
#include "smartBulb.h"
#include "smartSocket.h"

#include <vector>

class smartManager {
    private:
        vector<int> deviceIds;

        int smartBulbsNum = 0;
        vector<smartBulb*> smartBulbs;
        int smartSocketsNum = 0;
        vector<smartSocket*> smartSockets;
        int smartThermostatsNum = 0;
        vector<smartThermostat*> smartThermostats;
        int smartThermometersNum = 0;
        vector<smartThermometer*> smartThermometers;
        bool checkDevId(int id);
    public:
        int addSmartBulb(Network netSettings, string name, int id);
        int deleteSmartBulb(int id);
        int addSmartSocket(Network netSettings, string name, int id);
        int deleteSmartSocket(int id);
        int addSmartThermostat(Network netSettings, string name, int id);
        int deleteSmartThermostat(int id);
        int addSmartThermometer(Network netSettings, string name, int id);
        int deleteSmartThermometer(int id);

        void printSmartDevices();

        
};