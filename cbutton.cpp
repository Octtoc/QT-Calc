#include "cbutton.h"
#include "ui_cbutton.h"

CButton::CButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CButton)
{
    ui->setupUi(this);
}

CButton::~CButton()
{
    delete ui;
}
