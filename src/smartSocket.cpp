#include "smartSocket.h"

bool smartSocket::setIsTimerMode(bool isTimerMode) {
    this->isTimerMode = isTimerMode;
}
bool smartSocket::getIsTimerMode() {
    return isTimerMode;
}
bool smartSocket::setWorkingHours(time_t on, time_t off) {
    this->onTime = on;
    this->offTime = off;
    return true;
}
bool smartSocket::getWorkingHours(time_t* on, time_t* off) {
    *on = this->onTime;
    *off = this->offTime;
    return true;
}