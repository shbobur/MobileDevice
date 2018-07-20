#ifndef DEVICESCREENWIDGET_NEW_H
#define DEVICESCREENWIDGET_NEW_H

#include <QVBoxLayout>
#include <QWidget>
#include "devicescreenportrait.h"

class QPixmap;

namespace Ui {
class DeviceScreenWidget;
}

class DeviceScreenWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceScreenWidget(QWidget *parent = 0);
    ~DeviceScreenWidget();

private:
    Ui::DeviceScreenWidget *ui;

    QVBoxLayout *lytPortrait;
    DeviceScreen *screenPortrait;
};

#endif // DEVICESCREENWIDGET_H
