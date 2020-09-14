#ifndef ELECTIONSQT_H
#define ELECTIONSQT_H

#include <QtGui/QMainWindow>
#include "ui_electionsqt.h"

class ElectionsQt : public QMainWindow
{
    Q_OBJECT

public:
    ElectionsQt(QWidget *parent = 0);
    ~ElectionsQt();

private:
    Ui::ElectionsQtClass ui;
};

#endif // ELECTIONSQT_H
