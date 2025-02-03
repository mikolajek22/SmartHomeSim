#include "smartDevice.h"
#include <time.h>

class smartSocket : public smartDevice {
    private:
        bool isTimerMode;
        time_t onTime;
        time_t offTime;
    public:
        using smartDevice::smartDevice;
        bool setIsTimerMode(bool isTimerMode);
        bool getIsTimerMode();
        bool setWorkingHours(time_t on, time_t off);
        bool getWorkingHours(time_t* on, time_t* off);
};