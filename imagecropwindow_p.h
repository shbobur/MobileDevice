#ifndef IMAGECROPWINDOW_P_H
#define IMAGECROPWINDOW_P_H

#include <QWidget>

class QLabel;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QFrame;

class CropWindowComponents: public QWidget
{
public:
    CropWindowComponents(QWidget *parent = nullptr);

    QPushButton *changeBtn;
    QPushButton *cropBtn;
    QPushButton *continueBtn;
    QPushButton *cancelBtn;
};

class HorizontalWindow : public CropWindowComponents
{
    Q_OBJECT
public:
    HorizontalWindow(QWidget *parent = nullptr);
};

class VerticalWindow : public CropWindowComponents
{
    Q_OBJECT
public:
    VerticalWindow(QWidget *parent = nullptr);
};

#endif // IMAGECROPWINDOW_P_H
