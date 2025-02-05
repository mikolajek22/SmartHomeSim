#include "guiBasePage.h"
#include <QLabel>
class guiPageControl : public guiBasePage {
Q_OBJECT
    public:
        explicit guiPageControl(QStackedWidget *stackWidget ,QWidget *parent = nullptr) : guiBasePage(stackWidget, parent) {
            QLabel *labelMain = new QLabel("Control Page", this);
            labelMain->setStyleSheet("QLabel {font-size: 22px 'Arial'; font-weight: bold;}");
            labelMain->setAlignment(Qt::AlignTop);
            labelMain->setAlignment(Qt::AlignHCenter);
            addContentWidget(labelMain);
        }
};