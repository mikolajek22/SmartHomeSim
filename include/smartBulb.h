#include "smartDevice.h"

class smartBulb : public smartDevice {
    private:
        int brightness;
    public:
        using smartDevice::smartDevice;     //get constructor from paren class
        void  setBrightness(int brightness);
        int   getBrightness();
};