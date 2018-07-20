#include "devicescreenportrait.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QGraphicsView>
#include <QLabel>

DeviceScreenPortrait::DeviceScreenPortrait(QWidget *parent) :
    DeviceScreen(parent)
{
    // layout for 3 buttons on the surface
    QHBoxLayout *lytSurfaceBtns = new QHBoxLayout;
    lytSurfaceBtns->addWidget(this->btnRecentApps);
    lytSurfaceBtns->addWidget(this->btnHome);
    lytSurfaceBtns->addWidget(this->btnBack);

    // set Graphics View size
    playerGraphicsView->setFixedWidth(ShortSide);
    playerGraphicsView->setFixedHeight(LongSide);
    playerGraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    playerGraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    playerGraphicsView->setSceneRect(0, 0, ShortSide, LongSide);

    QVBoxLayout *lytMain = new QVBoxLayout(this);
    lytMain->setMargin(0);
    lytMain->setSpacing(2);
    lytMain->addWidget(this->toolBox);
//    lytMain->addStretch();
    lytMain->addWidget(this->playerGraphicsView);
//    lytMain->addStretch();
    lytMain->addLayout(lytSurfaceBtns);

    this->setLayout(lytMain);
}

DeviceScreenPortrait::~DeviceScreenPortrait()
{

}

QSize DeviceScreenPortrait::sceneSize()
{
    return QSize(ShortSide, LongSide);
}
