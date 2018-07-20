#include "devicescreen.h"

#include <QGraphicsView>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QRegularExpression>
#include <QHBoxLayout>
#include <QMouseEvent>

DeviceScreen::DeviceScreen(QWidget *parent) : QWidget(parent)
{
    // screen of mobile device
    playerGraphicsView = new QGraphicsView(this);
    playerScene = new QGraphicsScene(this);
    playerGraphicsView->setScene(playerScene);

    playerGraphicsView->setCursor(QCursor(Qt::PointingHandCursor));

    createButtons();

}

DeviceScreen::~DeviceScreen()
{
    // screen of mobile device
    delete playerGraphicsView;
    delete playerScene;

    // control buttons
    // on the surface (home, back, Overview (app chooser))
    delete btnHome;
    delete btnBack;
    delete btnRecentApps;

    // on the sides (Power on/off, Volume up/down)
    delete btnSleep;
    delete btnWakeUp;
    delete btnSetLeft;
    delete btnSetNatural;
    delete btnSetRight;

    // other buttons
    delete btnNotification;
    delete btnQuickSettings;
    delete btnSearch;
    delete toolBox;
}

void DeviceScreen::createButtons()
{
    // control buttons
    // on the surface (home, back, Overview (app chooser))
    // Home Button
    btnHome = new QPushButton(this);
    btnHome->setIcon(QIcon(":/main/controlButtons/images/iconHome.png"));
    btnHome->setToolTip(tr("Home"));

    // Back button
    btnBack = new QPushButton(this);
    btnBack->setIcon(QIcon(":/main/controlButtons/images/iconBack.png"));
    btnBack->setToolTip("Back");

    // Recent apps (or Overview) button
    btnRecentApps = new QPushButton(this);
    btnRecentApps->setIcon(QIcon(":/main/controlButtons/images/iconRecentApps.png"));
    btnRecentApps->setToolTip(tr("Recent applications"));

    // other buttons
    // Open notifications button
    btnNotification = new QPushButton(this);
    btnNotification->setIcon(QIcon(":/main/controlButtons/images/iconNotificationsOn.png"));
    btnNotification->setToolTip(tr("Open notifications"));

    // Quick Settins button
    btnQuickSettings = new QPushButton(this);
    btnQuickSettings->setIcon(QIcon(":/main/controlButtons/images/iconQuickSettings.png"));
    btnQuickSettings->setToolTip(tr("Open quick settings"));

    // Search button
    btnSearch = new QPushButton(this);
    btnSearch->setIcon(QIcon(":/main/controlButtons/images/iconSearch.png"));
    btnSearch->setToolTip(tr("Search"));


    // on the sides (Sleep/WakeUp device)
    toolBox = new QWidget(this);

    btnSleep = new QPushButton(this);
    btnSleep->setIcon(QIcon(":/main/controlButtons/images/iconScreenOff.png"));
    btnSleep->setToolTip(tr("Sleep the device screen"));

    btnWakeUp = new QPushButton(this);
    btnWakeUp->setIcon(QIcon(":/main/controlButtons/images/iconScreenOn.png"));
    btnWakeUp->setToolTip(tr("Wake up the device screen"));

    // set Left/Natural/Right orientation buttons
    // SetOrientationLeft button
    btnSetLeft = new QPushButton(this);
    btnSetLeft->setIcon(QIcon(":/main/controlButtons/images/iconOrientationLeft.png"));
    btnSetLeft->setToolTip(tr("Sets orientation to left landscape"));

    // SetOrientationNatural button
    btnSetNatural = new QPushButton(this);
    btnSetNatural->setIcon(QIcon(":/main/controlButtons/images/iconOrientationNatural.png"));
    btnSetNatural->setToolTip(tr("Sets oreintation to natural portrait"));

    // SetOrientationRight button
    btnSetRight = new QPushButton(this);
    btnSetRight->setIcon(QIcon(":/main/controlButtons/images/iconOrientationRight.png"));
    btnSetRight->setToolTip(tr("Sets orientation to right landscape"));

    QHBoxLayout *lyt = new QHBoxLayout;
    lyt->setMargin(0);
    lyt->setSpacing(2);
    lyt->addWidget(btnNotification);
    lyt->addWidget(btnQuickSettings);
    lyt->addWidget(btnSearch);
    lyt->addWidget(btnSetLeft);
    lyt->addWidget(btnSetNatural);
    lyt->addWidget(btnSetRight);
    lyt->addWidget(btnSleep);
    lyt->addWidget(btnWakeUp);
    toolBox->setMaximumWidth(ShortSide);
    toolBox->setLayout(lyt);
}
