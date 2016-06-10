#ifndef CMULTIFUNCTIONALBUTTON_H
#define CMULTIFUNCTIONALBUTTON_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QVector>
#include <QString>
#include "stdafx.h"
#include "cbutton.h"

class CMultifunctionalButton : public CButton
{
    Q_OBJECT

protected:
    QVector<QString> multiplecalcvalues;
public:
    explicit CMultifunctionalButton(QWidget *parent = 0);
};

#endif // CMULTIFUNCTIONALBUTTON_H
