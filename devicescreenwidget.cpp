#include "devicescreenwidget.h"
#include "ui_devicescreenwidget.h"

#include <QDebug>
#include <QPixmap>
#include <QPushButton>
#include <QKeyEvent>
#include <QInputDialog>

#define LAYOUT_MARGIN 9

DeviceScreenWidget::DeviceScreenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceScreenWidget)
{
    ui->setupUi(this);

    ui->stackedWidget->setProperty("deviceView", QVariant("light"));

    screenPortrait = new DeviceScreenPortrait(this);

    // portrait screen layout
    lytPortrait = new QVBoxLayout;
    lytPortrait->setMargin(LAYOUT_MARGIN);
    lytPortrait->addWidget(screenPortrait);

    ui->page->setLayout(lytPortrait);
    ui->stackedWidget->setCurrentIndex(0);

}

DeviceScreenWidget::~DeviceScreenWidget()
{
    delete ui;
}

