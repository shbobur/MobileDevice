#include "imagecropperwindow.h"

#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

ImageCropperWindow::ImageCropperWindow(QWidget *parent) : QWidget(parent)
{
    horizWindow = new HorizontalWindow(this);
    verticalWindow = new VerticalWindow(this);

    connect(horizWindow->changeBtn, &QPushButton::clicked,
            this, &ImageCropperWindow::changeWindowOrientation);
    connect(verticalWindow->changeBtn, &QPushButton::clicked,
            this, &ImageCropperWindow::changeWindowOrientation);

//    connect(horizWindow->cropBtn, &QPushButton::clicked, this, &ImageCropperWindow::crop);
//    connect(verticalWindow->cropBtn, &QPushButton::clicked, this, &ImageCropperWindow::crop);

//    connect(horizWindow->continueBtn, &QPushButton::clicked, this, &ImageCropperWindow::requestAgent);
//    connect(verticalWindow->continueBtn, &QPushButton::clicked, this, &ImageCropperWindow::requestAgent);

//    connect(horizWindow->cancelBtn, &QPushButton::clicked, this, &ImageCropperWindow::close);
//    connect(verticalWindow->cancelBtn, &QPushButton::clicked, this, &ImageCropperWindow::close);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(3);
    layout->addWidget(horizWindow);
    layout->addWidget(verticalWindow);
    verticalWindow->setVisible(false);

    setLayout(layout);
}

ImageCropperWindow::~ImageCropperWindow()
{
}

void ImageCropperWindow::changeWindowOrientation()
{
    if (horizWindow->isVisible()) {
        horizWindow->setVisible(false);
        verticalWindow->setVisible(true);
    }
    else {
        verticalWindow->setVisible(false);
        horizWindow->setVisible(true);
    }

    this->resize(this->minimumSizeHint());
}
