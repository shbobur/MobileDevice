#ifndef DEVICESCREEN_H
#define DEVICESCREEN_H

#include <QGraphicsScene>
#include <QWidget>

class QGraphicsView;
class QPushButton;
class QLabel;

enum {ShortSide = 360, LongSide = 640};

class DeviceScreen : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceScreen(QWidget *parent = nullptr);
    ~DeviceScreen();

    virtual QSize sceneSize() = 0;

    // screen of mobile device
    QGraphicsView *playerGraphicsView;
    QGraphicsScene *playerScene;

    // control buttons
    // on the surface (home, back, Overview (app chooser))
    QPushButton *btnHome;
    QPushButton *btnBack;
    QPushButton *btnRecentApps;

    // on the sides (Power on/off, Volume up/down)
    QWidget *toolBox;
    QPushButton *btnSleep;
    QPushButton *btnWakeUp;
    QPushButton *btnSetLeft;
    QPushButton *btnSetNatural;
    QPushButton *btnSetRight;

    // Other buttons
    QPushButton *btnNotification;
    QPushButton *btnQuickSettings;
    QPushButton *btnSearch;

private:        // methods
    void createButtons();

};

#endif // DEVICESCREEN_H
