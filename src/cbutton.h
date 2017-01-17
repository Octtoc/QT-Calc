#ifndef CBUTTON_H
#define CBUTTON_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include "stdafx.h"

class CButton : public QPushButton
{
    Q_OBJECT

public:
    QString calcvalue;
    CalcButtonType type;
    explicit CButton(QWidget *parent = 0);
    ~CButton();
};

#endif // CBUTTON_H
