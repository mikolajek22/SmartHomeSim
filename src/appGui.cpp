#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include "guiPageMain.h"
#include "guiPageConfig.h"
#include "guiPageControl.h"
#include <QMainWindow>

int appGui_main(int argc, char* argv[]){
    QApplication guiApp(argc, argv);

    // Main window:
    // QWidget window;
    QMainWindow mainWindow;
    // window.setWindowTitle("Smart Home Manager");
    // window.resize(900,600);    
    QStackedWidget *stackedWidget = new QStackedWidget;

    guiPageMain *pageMain = new guiPageMain(stackedWidget);
    guiPageConfig *pageConfig = new guiPageConfig(stackedWidget);
    guiPageControl *pageControl = new guiPageControl(stackedWidget);

    stackedWidget->addWidget(pageMain);
    stackedWidget->addWidget(pageConfig);
    stackedWidget->addWidget(pageControl);

    mainWindow.setCentralWidget(stackedWidget);
    // QVBoxLayout *layout = new QVBoxLayout(&window);
    // layout->addWidget(stackedWidget);
    // window.setLayout(layout);
    
    
    mainWindow.show();
    
    return guiApp.exec();
}    
