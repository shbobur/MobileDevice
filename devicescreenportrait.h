#ifndef DEVICESCREENPORTRAIT_H
#define DEVICESCREENPORTRAIT_H

#include "devicescreen.h"

class DeviceScreenPortrait : public DeviceScreen
{
    Q_OBJECT
public:
    DeviceScreenPortrait(QWidget *parent = nullptr);
    ~DeviceScreenPortrait();

    virtual QSize sceneSize();
};

#endif // DEVICESCREENPORTRAIT_H
