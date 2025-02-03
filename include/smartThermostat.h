#include "smartDevice.h"

class smartThermostat : public smartDevice {
    private:
        int power;
        int temp;
    public:
        using smartDevice::smartDevice;
        bool setTemp(int temp);
        int getTemp();

        bool setPower(int power);
        int getPower();
};