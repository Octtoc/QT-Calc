#ifndef CBUTTON_H
#define CBUTTON_H

#include <QWidget>

namespace Ui {
class CButton;
}

class CButton : public QWidget
{
    Q_OBJECT

public:
    explicit CButton(QWidget *parent = 0);
    ~CButton();

private:
    Ui::CButton *ui;
};

#endif // CBUTTON_H
