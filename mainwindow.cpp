#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDockWidget>

#include "devicescreenwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QLabel *centralWidget = new QLabel(tr("central widget"));
    centralWidget->setStyleSheet("background-color: green");
    setCentralWidget(centralWidget);

    QDockWidget *deviceDockable = new QDockWidget(tr("Device"), this);
    deviceDockable->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    deviceDockable->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    deviceDockable->setFeatures(QDockWidget::DockWidgetFloatable);

    DeviceScreenWidget *deviceScreenWidget = new DeviceScreenWidget(this);

    deviceDockable->setWidget(deviceScreenWidget);
    deviceDockable->setMaximumSize(deviceScreenWidget->minimumSizeHint());

    addDockWidget(Qt::RightDockWidgetArea, deviceDockable);
}

MainWindow::~MainWindow()
{
    delete ui;
}
