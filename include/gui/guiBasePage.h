#ifndef GUIBASEPAGE_H
#define GUIBASEPAGE_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QScrollArea>
#include <QStackedWidget>
#include <iostream>
#include <QPushButton>
using namespace std;
class guiBasePage : public QWidget {
    Q_OBJECT
    public:
        explicit guiBasePage(QStackedWidget *stackWidget,QWidget *parent = nullptr) : QWidget(parent) {
            // Main Layout -> navigation bar (left) + Content (right)
            QHBoxLayout *mainLayout = new QHBoxLayout(this);
            mainLayout->setContentsMargins(0, 0, 0, 0);

            // Navigation bar:
            QWidget *navWidget = new QWidget(this);
            navWidget->setFixedWidth(200);
            QVBoxLayout *navLayout = new QVBoxLayout(navWidget);
            navLayout->setContentsMargins(10,10,10,10);

            QPushButton *btnMain = new QPushButton("Main Menu", navWidget);
            QPushButton *btnConfig = new QPushButton("Config Menu", navWidget);
            QPushButton *btnControl = new QPushButton("Control Menu", navWidget);

            navLayout->addWidget(btnMain);
            navLayout->addWidget(btnConfig);
            navLayout->addWidget(btnControl);

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

            // connect(navList, &QListWidget::currentRowChanged, stackWidget, &QStackedWidget::setCurrentIndex);
            connect(btnMain, &QPushButton::clicked, [stackWidget](){stackWidget->setCurrentIndex(0);});
            connect(btnConfig, &QPushButton::clicked, [stackWidget](){stackWidget->setCurrentIndex(1);});
            connect(btnControl, &QPushButton::clicked, [stackWidget](){stackWidget->setCurrentIndex(2);});

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