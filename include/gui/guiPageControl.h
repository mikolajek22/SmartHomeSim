#include "guiBasePage.h"
#include <QLabel>
class guiPageControl : public guiBasePage {
Q_OBJECT
    public:
        explicit guiPageControl(QWidget *parent = nullptr) : guiBasePage(parent) {
            QLabel *labelMain = new QLabel("Main Menu", this);
            labelMain->setStyleSheet("QLabel {font-size: 22px 'Arial'; font-weight: bold;}");
            labelMain->setAlignment(Qt::AlignTop);
            labelMain->setAlignment(Qt::AlignHCenter);
        }
};