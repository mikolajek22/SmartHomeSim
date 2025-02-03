#include "smartDevice.h"

class smartThermometer : public smartDevice {
    private:
        int temp;
    public:
        int getTemp();
        using smartDevice::smartDevice;
};