#ifndef GUIBASEPAGE_H
#define GUIBASEPAGE_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QScrollArea>
#include <QStackedWidget>
#include <iostream>
using namespace std;
class guiBasePage : public QWidget {
    Q_OBJECT
    public:
        explicit guiBasePage(QWidget *parent = nullptr) : QWidget(parent) {
            // Main Layout -> navigation bar (left) + Content (right)
            QHBoxLayout *mainLayout = new QHBoxLayout(this);
            mainLayout->setContentsMargins(0, 0, 0, 0);

            // Navigation bar:
            QWidget *navWidget = new QWidget(this);
            navWidget->setFixedWidth(200);
            QVBoxLayout *navLayout = new QVBoxLayout(navWidget);
            navLayout->setContentsMargins(10,10,10,10);

            // Navigation bar -> including:
            QListWidget *navList = new QListWidget(navWidget);
            navList->addItem("Main Menu");
            navList->addItem("Configure Devices");
            navList->addItem("Control Devices");
            navLayout->addWidget(navList);

            navWidget->setStyleSheet("background-color: #807c7c;");

            // Content bar:
            QScrollArea *contentArea = new QScrollArea(this);
            contentArea->setWidgetResizable(true);
            contentArea->setStyleSheet("background-color: #f0f0f0");

            // Content:
            contentWidget = new QWidget();
            contentArea->setWidget(contentWidget);

            // inside
            contentLayout = new QVBoxLayout(contentWidget);
            contentLayout->setContentsMargins(10,10,10,10);

            // add nav bar and content to the main page
            mainLayout->addWidget(navWidget);
            mainLayout->addWidget(contentArea);

        }
        void addContentWidget(QWidget *widget) {
            contentLayout->addWidget(widget);
        }
    ~guiBasePage() {}
    
    protected:
        QVBoxLayout *contentLayout;
        QWidget *contentWidget;
};
#endif