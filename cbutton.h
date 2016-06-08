#ifndef CBUTTON_H
#define CBUTTON_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>

class CButton : public QPushButton
{
    Q_OBJECT

public:
    QString calcvalue;
    explicit CButton(QWidget *parent = 0);
    ~CButton();
};

#endif // CBUTTON_H
