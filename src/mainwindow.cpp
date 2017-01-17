#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <muparser/muparser.h>
#include <QTextCursor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isEqual = false;
    this->setEnterPressed(false);

    ui->pushButton_number0->type = CalcButtonType::number;
    ui->pushButton_number1->type = CalcButtonType::number;
    ui->pushButton_number2->type = CalcButtonType::number;
    ui->pushButton_number3->type = CalcButtonType::number;
    ui->pushButton_number4->type = CalcButtonType::number;
    ui->pushButton_number5->type = CalcButtonType::number;
    ui->pushButton_number6->type = CalcButtonType::number;
    ui->pushButton_number7->type = CalcButtonType::number;
    ui->pushButton_number8->type = CalcButtonType::number;
    ui->pushButton_number9->type = CalcButtonType::number;

    ui->pushButton_abs->type = CalcButtonType::function;
    ui->pushButton_log->type = CalcButtonType::function;
    ui->pushButton_number_cos->type = CalcButtonType::function;
    ui->pushButton_number_sin->type = CalcButtonType::function;
    ui->pushButton_number_sqrt->type = CalcButtonType::function;
    ui->pushButton_number_tan->type = CalcButtonType::function;

    ui->pushButton_enter->type = CalcButtonType::enter;

    ui->pushButton_number0->calcvalue = QString("0");
    ui->pushButton_number1->calcvalue = QString("1");
    ui->pushButton_number2->calcvalue = QString("2");
    ui->pushButton_number3->calcvalue = QString("3");
    ui->pushButton_number4->calcvalue = QString("4");
    ui->pushButton_number5->calcvalue = QString("5");
    ui->pushButton_number6->calcvalue = QString("6");
    ui->pushButton_number7->calcvalue = QString("7");
    ui->pushButton_number8->calcvalue = QString("8");
    ui->pushButton_number9->calcvalue = QString("9");

    ui->pushButton_exp_plus->calcvalue = QString("+");
    ui->pushButton_exp_minus->calcvalue = QString("-");
    ui->pushButton_exp_mal->calcvalue = QString("*");
    ui->pushButton_exp_geteilt->calcvalue = QString("/");
    ui->pushButton_e->calcvalue = QString("_e");
    ui->pushButton_exp_plus->calcvalue = QString("+");
    ui->pushButton_abs->calcvalue = QString("abs(");
    ui->pushButton_log->calcvalue = QString("log(");
    ui->pushButton_number_komma->calcvalue = QString(".");
    ui->pushButton_number_sin->calcvalue = QString("sin(");
    ui->pushButton_number_cos->calcvalue = QString("cos(");
    ui->pushButton_number_tan->calcvalue = QString("tan(");
    ui->pushButton_number_sqrt->calcvalue = QString("sqrt(");
    ui->pushButton_pi->calcvalue = QString("_pi");
    ui->pushButton_pow->calcvalue = QString("^");
    ui->pushButton_number_klauf->calcvalue = QString("(");
    ui->pushButton_number_klzu->calcvalue = QString(")");

    connect(ui->pushButton_number0, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number1, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number2, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number3, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number4, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number5, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number6, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number7, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number8, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number9, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_exp_plus, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_exp_minus, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_exp_mal, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_exp_geteilt, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_abs, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_e, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_log, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number_komma, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number_sin, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number_cos, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number_tan, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number_sqrt, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_pi, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_pow, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number_klauf, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));
    connect(ui->pushButton_number_klzu, SIGNAL(clicked(bool)),this,SLOT(on_pushButton_clicked()));

    ui->pushButton_number0->setShortcut(QKeySequence("0"));
    ui->pushButton_number1->setShortcut(QKeySequence("1"));
    ui->pushButton_number2->setShortcut(QKeySequence("2"));
    ui->pushButton_number3->setShortcut(QKeySequence("3"));
    ui->pushButton_number4->setShortcut(QKeySequence("4"));
    ui->pushButton_number5->setShortcut(QKeySequence("5"));
    ui->pushButton_number6->setShortcut(QKeySequence("6"));
    ui->pushButton_number7->setShortcut(QKeySequence("7"));
    ui->pushButton_number8->setShortcut(QKeySequence("8"));
    ui->pushButton_number9->setShortcut(QKeySequence("9"));

    ui->pushButton_exp_plus->setShortcut(QKeySequence("+"));
    ui->pushButton_exp_minus->setShortcut(QKeySequence("-"));
    ui->pushButton_exp_mal->setShortcut(QKeySequence("*"));
    ui->pushButton_exp_geteilt->setShortcut(QKeySequence("/"));
    ui->pushButton_number_komma->setShortcut(QKeySequence(","));

    ui->pushButton_enter->setShortcut(QKeySequence("Enter"));
    ui->pushButton_back->setShortcut(QKeySequence("Backspace"));

    //model = new QStringListModel(this);
    //model->setStringList(history);
    //ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::getEnterPressed()
{
    return _enterPressed;
}

void MainWindow::setEnterPressed(bool enter)
{
    _enterPressed = enter;
}

void MainWindow::PressCalcButton(QString text)
{
    AddCalcText(text);
    this->setEnterPressed(false);
}

void MainWindow::PressCalcButton(QString text, CalcButtonType type)
{
    if (this->getEnterPressed() &&
            ( type == CalcButtonType::number || type == CalcButtonType::function ) )
    {
        ui->lineEdit->setText("");
        AddCalcText(text);
    }
    else
    {
        AddCalcText(text);
    }
    this->setEnterPressed(false);
}

void MainWindow::on_pushButton_enter_clicked()
{
    QString calcexpression = ui->lineEdit->text();
    history.append(calcexpression);
    ui->lineEdit->setText(Calculate(calcexpression));

    //model->setStringList(history);

    this->setEnterPressed(true);
}

void MainWindow::on_pushButton_clicked()
{
    QObject* obj = sender();
    CButton *button = static_cast<CButton *>(obj);
    if (button != NULL)
    {
        PressCalcButton(button->calcvalue, button->type);
    }
}

void MainWindow::on_pushButton_back_clicked()
{
    static bool test = true;

    if (test)
    {
        ui->pushButton_number_sin->calcvalue = "asin(";
        ui->pushButton_number_tan->calcvalue = "atan(";
        ui->pushButton_number_cos->calcvalue = "acos(";
        ui->pushButton_number_sin->setText("asin\nsin");
        ui->pushButton_number_tan->setText("atan");
        ui->pushButton_number_cos->setText("acos");
        test = false;
    }
    else
    {
        ui->pushButton_number_sin->calcvalue = "sin(";
        ui->pushButton_number_tan->calcvalue = "tan(";
        ui->pushButton_number_cos->calcvalue = "cos(";
        ui->pushButton_number_sin->setText("sin\nasin");
        ui->pushButton_number_tan->setText("tan");
        ui->pushButton_number_cos->setText("cos");
        test = true;
    }
    if (!this->getEnterPressed())
    {
        RemoveCalcText(ui->lineEdit->text().size()-1,ui->lineEdit->text().size());
    }
}

void MainWindow::on_pushButton_number_C_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_number_CE_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_textEdit_textChanged()
{
    if (ui->lineEdit->text().size()>10)
    {
        QFont font = ui->lineEdit->font();
        int textSize = 60-(ui->lineEdit->text().size());
        font.setPixelSize(textSize);
        //ui->lineEdit->font.setPixelSize(textSize);
        ui->lineEdit->setFont(font);
    }
}

QString MainWindow::Calculate(QString cStr)
{
    try
    {
        mu::Parser p;
        p.SetExpr(cStr.toStdString());
        std::stringstream buffer;
        buffer << p.Eval();
        currentResult = QString::fromStdString(buffer.str());
    }
    catch (mu::Parser::exception_type &e)
    {
        currentResult = "Parser Error";
    }

    return currentResult;
}

void MainWindow::AddCalcText(QString txtstr)
{
    isEqual=false;
    if(isEqual)
    {
        isEqual=false;
        ui->lineEdit->setText("");
        ui->lineEdit->setText(txtstr);
    }
    else
    {
        ui->lineEdit->setText(ui->lineEdit->text()+txtstr);
    }
}

void MainWindow::RemoveCalcText(int from, int to)
{
    ui->lineEdit->setText(ui->lineEdit->text().remove(from, to));
}
