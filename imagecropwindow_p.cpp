#include "imagecropwindow_p.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

CropWindowComponents::CropWindowComponents(QWidget *parent) :
    QWidget(parent)
{
    changeBtn = new QPushButton(tr("Change"), this);
    cropBtn = new QPushButton(tr("Crop"), this);
    continueBtn = new QPushButton(tr("Continue"), this);
    cancelBtn = new QPushButton(tr("Cancel"), this);
}

HorizontalWindow::HorizontalWindow(QWidget *parent) :
    CropWindowComponents(parent)
{
    QHBoxLayout *btnsLyt = new QHBoxLayout;
    btnsLyt->setMargin(0);
    btnsLyt->addWidget(changeBtn);
    btnsLyt->addWidget(cropBtn);
    btnsLyt->addWidget(continueBtn);
    btnsLyt->addWidget(cancelBtn);
    btnsLyt->addStretch();

    setLayout(btnsLyt);
}

VerticalWindow::VerticalWindow(QWidget *parent) :
    CropWindowComponents(parent)
{
    QVBoxLayout *btnsLyt = new QVBoxLayout;
    btnsLyt->setMargin(0);
    btnsLyt->addWidget(changeBtn);
    btnsLyt->addWidget(cropBtn);
    btnsLyt->addWidget(continueBtn);
    btnsLyt->addWidget(cancelBtn);
    btnsLyt->addStretch();

    setLayout(btnsLyt);
}
