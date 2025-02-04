#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include "guiPageMain.h"
#include "guiPageConfig.h"
#include "guiPageControl.h"

int appGui_main(int argc, char* argv[]){
    QApplication guiApp(argc, argv);

    // Main window:
    QWidget window;
    window.setWindowTitle("Smart Home Manager");
    window.resize(900,600);    
    QStackedWidget *stackedWidget = new QStackedWidget(&window);

    guiPageMain *pageMain = new guiPageMain();
    guiPageConfig *pageConfig = new guiPageConfig();
    guiPageControl *pageControl = new guiPageControl();

    stackedWidget->addWidget(pageMain);
    stackedWidget->addWidget(pageConfig);
    stackedWidget->addWidget(pageControl);


    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(stackedWidget);
    window.setLayout(layout);

    
    
    window.show();
    
    return guiApp.exec();
}    
