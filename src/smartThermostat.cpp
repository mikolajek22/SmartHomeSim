#include "smartThermostat.h"

bool smartThermostat::setTemp(int temp) {
    if (temp > 32 || temp < 16) {
        return false;
    } 
    else {
        this->temp = temp;
    }
    return true;
}
int smartThermostat::getTemp() {
    return this->temp;
}

bool smartThermostat::setPower(int power) {
    if (power > 100 || power < 0) {
        return false;
    } 
    else {
        this->power = power;
    }
    return true;
}
int smartThermostat::getPower() {
    return this->power;
}