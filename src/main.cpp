#include "appMenu.h"
#include <thread>

int main() {
    std::thread menuThread(appMenu_main);
    menuThread.join();
    return 0;
}
