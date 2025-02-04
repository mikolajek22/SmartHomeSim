#include "guiBasePage.h"
#include <QLabel>
class guiPageConfig : public guiBasePage {
    Q_OBJECT
    public:
        explicit guiPageConfig(QWidget *parent = nullptr) : guiBasePage(parent) {
            QLabel *labelMain = new QLabel("Config Menu", this);
            labelMain->setStyleSheet("QLabel {font-size: 22px 'Arial'; font-weight: bold;}");
            labelMain->setAlignment(Qt::AlignTop);
            labelMain->setAlignment(Qt::AlignHCenter);
        }
};