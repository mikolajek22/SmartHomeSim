#include "guiBasePage.h"
#include <QLabel>
#include <QPushButton>

class guiPageMain : public guiBasePage {
    Q_OBJECT
public:
    explicit guiPageMain(QWidget *parent = nullptr) : guiBasePage(parent) {

        QLabel *labelMain = new QLabel("Main Menu", this);
        labelMain->setStyleSheet("QLabel {font-size: 22px 'Arial'; font-weight: bold;}");
        labelMain->setAlignment(Qt::AlignTop);
        labelMain->setAlignment(Qt::AlignHCenter);

        QPushButton *btn1 = new QPushButton("click me lol", this);
        addContentWidget(labelMain);
        addContentWidget(btn1);       
    }
    ~guiPageMain() {}
};