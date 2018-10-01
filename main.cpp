#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QTranslator>

#include "imagecropperwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator newLang;
    newLang.load(":/translations/newLanguage.qm");

    a.installTranslator(&newLang);

    ImageCropperWindow w;
    w.show();

    return a.exec();
}
