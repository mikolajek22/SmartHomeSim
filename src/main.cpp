#include "appMenu.h"
#include <thread>
#include "appGui.h"

int main(int argc, char *argv[]) {
    

    std::thread guiThread(appGui_main, argc, argv);
    std::thread menuThread(appMenu_main);
    menuThread.join();
    guiThread.join();
    return 0;
}
