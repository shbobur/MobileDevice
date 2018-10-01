#ifndef IMAGECROPPERWINDOW_H
#define IMAGECROPPERWINDOW_H

#include "imagecropwindow_p.h"

class ImageCropperWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ImageCropperWindow(QWidget *parent = nullptr);
    ~ImageCropperWindow();

private slots:
    void changeWindowOrientation();

private:
    HorizontalWindow *horizWindow;
    VerticalWindow *verticalWindow;

    QPixmap lastCroppedImage;
    QPointF cropPoint;
    QSizeF cropSize;
    QSize imageSize;
};

#endif // IMAGECROPPERWINDOW_H
