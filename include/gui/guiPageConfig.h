#include "guiBasePage.h"
#include <QLabel>
#include <QGridLayout>
#include <QDialog>

class guiPageConfig : public guiBasePage {
    Q_OBJECT
    public:
        explicit guiPageConfig(QStackedWidget *stackWidget ,QWidget *parent = nullptr) : guiBasePage(stackWidget, parent) {
            QLabel *labelMain = new QLabel("Config Menu", this);
            labelMain->setStyleSheet("QLabel {font-size: 22px 'Arial'; font-weight: bold;}");
            labelMain->setAlignment(Qt::AlignTop);
            labelMain->setAlignment(Qt::AlignHCenter);
            addContentWidget(labelMain);

            // Buttons:
            QWidget *buttonContainer = new QWidget(this);
            QGridLayout *gridLayout = new QGridLayout(buttonContainer);
            QPushButton *btnAddDevice = new QPushButton("Add Device", buttonContainer);
            QPushButton *btnRmvDevice = new QPushButton("Remove Device", buttonContainer);
            QPushButton *btnDisplayDevices = new QPushButton("Display Devices", buttonContainer);
            gridLayout->addWidget(btnAddDevice, 0, 0);
            gridLayout->addWidget(btnRmvDevice, 0, 1);
            gridLayout->addWidget(btnDisplayDevices, 1, 0, 1, 2, Qt::AlignCenter);
            addContentWidget(buttonContainer);

            // button events:
            connect(btnAddDevice, &QPushButton::clicked, this, &guiPageConfig::showPopUp);

        }   
    private slots:
        void showPopUp() {
            QDialog *popupWindow = new QDialog(this);
            popupWindow->setWindowTitle("Add Device");

            // info
            QLabel *labelInfo = new QLabel("choose device",popupWindow);
            labelInfo->setAlignment(Qt::AlignTop);
            labelInfo->setAlignment(Qt::AlignHCenter);
            // buttons - devices
            QGridLayout *layoutDevices = new QGridLayout(popupWindow);
            QPushButton *btnBulb = new QPushButton("Bulb", popupWindow);
            QPushButton *btnSocket = new QPushButton("Socket", popupWindow);
            QPushButton *btnThermometer = new QPushButton("Thermometer", popupWindow);
            QPushButton *btnThermostat = new QPushButton("Thermostat", popupWindow);
            
            layoutDevices->addWidget(btnBulb, 0, 0);
            layoutDevices->addWidget(btnSocket, 0, 1);
            layoutDevices->addWidget(btnThermometer, 1, 0);
            layoutDevices->addWidget(btnThermostat, 1, 1);
       
            popupWindow->exec();
            std::cout << "POP UP" << std::endl;
        }
};