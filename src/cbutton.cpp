#include "cbutton.h"

CButton::CButton(QWidget *parent) :
    QPushButton(parent)
{
    this->type = CalcButtonType::other;
}

CButton::~CButton()
{

}
