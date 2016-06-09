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

    ui->pushButton_enter->setShortcut(QKeySequence("Enter"));
    ui->pushButton_back->setShortcut(QKeySequence("Backspace"));

    ui->pushButton_e->calcvalue = QString("_e");

    model = new QStringListModel(this);
    model->setStringList(history);
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
    if (this->getEnterPressed() && type == CalcButtonType::number)
    {
        ui->textEdit->setText("");
        AddCalcText(text);
        this->setEnterPressed(false);
    }
    else
    {
        AddCalcText(text);
    }
}

void MainWindow::on_pushButton_enter_clicked()
{
    QString calcexpression = ui->textEdit->toPlainText();
    history.append(calcexpression);
    ui->textEdit->setText(Calculate(calcexpression));

    model->setStringList(history);

    this->setEnterPressed(true);
}

void MainWindow::on_pushButton_number0_clicked()
{
    PressCalcButton("0",CalcButtonType::number);
}

void MainWindow::on_pushButton_number1_clicked()
{
    PressCalcButton("1",CalcButtonType::number);
}

void MainWindow::on_pushButton_number2_clicked()
{
    PressCalcButton("2",CalcButtonType::number);
}

void MainWindow::on_pushButton_number3_clicked()
{
    PressCalcButton("3",CalcButtonType::number);
}

void MainWindow::on_pushButton_number4_clicked()
{
    PressCalcButton("4",CalcButtonType::number);
}

void MainWindow::on_pushButton_number5_clicked()
{
    PressCalcButton("5",CalcButtonType::number);
}

void MainWindow::on_pushButton_number6_clicked()
{
    PressCalcButton("6",CalcButtonType::number);
}

void MainWindow::on_pushButton_number7_clicked()
{
    PressCalcButton("7",CalcButtonType::number);
}

void MainWindow::on_pushButton_number8_clicked()
{
    PressCalcButton("8",CalcButtonType::number);
}

void MainWindow::on_pushButton_number9_clicked()
{
    PressCalcButton("9",CalcButtonType::number);
}

void MainWindow::on_pushButton_exp_plus_clicked()
{
    PressCalcButton("+");
}

void MainWindow::on_pushButton_exp_minus_clicked()
{
    PressCalcButton("-");
}

void MainWindow::on_pushButton_exp_mal_clicked()
{
    PressCalcButton("*");
}

void MainWindow::on_pushButton_exp_geteilt_clicked()
{
    PressCalcButton("/");
}

void MainWindow::on_pushButton_number_sin_clicked()
{
    PressCalcButton("sin(");
}

void MainWindow::on_pushButton_number_cos_clicked()
{
    PressCalcButton("cos(");
}

void MainWindow::on_pushButton_number_tan_clicked()
{
    PressCalcButton("tan(");
}

void MainWindow::on_pushButton_number_sqrt_clicked()
{
    PressCalcButton("sqrt(");
}

void MainWindow::on_pushButton_number_klauf_clicked()
{
    PressCalcButton("(");
}

void MainWindow::on_pushButton_number_klzu_clicked()
{
    PressCalcButton(")");
}

void MainWindow::on_pushButton_pow_clicked()
{
    PressCalcButton("pow(");
}

void MainWindow::on_pushButton_log_clicked()
{
    PressCalcButton("log(");
}

void MainWindow::on_pushButton_abs_clicked()
{
    PressCalcButton("abs(");
}

void MainWindow::on_pushButton_pi_clicked()
{
    PressCalcButton("_pi");
}

void MainWindow::on_pushButton_back_clicked()
{
    if (!this->getEnterPressed())
    {
        RemoveCalcText(ui->textEdit->toPlainText().size()-1,ui->textEdit->toPlainText().size());
    }
}

void MainWindow::on_pushButton_number_C_clicked()
{
    ui->textEdit->setText("");
}

void MainWindow::on_pushButton_number_CE_clicked()
{
    ui->textEdit->setText("");
}

void MainWindow::AddCalcText(QString txtstr)
{
    isEqual=false;
    if(isEqual)
    {
        isEqual=false;
        ui->textEdit->setText("");
        ui->textEdit->setText(txtstr);
    }
    else
    {
        ui->textEdit->setText(ui->textEdit->toPlainText()+txtstr);
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
        currentResult ="Parser Error";
    }

    return currentResult;
}

void MainWindow::RemoveCalcText(int from, int to)
{
    ui->textEdit->setText(ui->textEdit->toPlainText().remove(from, to));
}

void MainWindow::on_pushButton_e_clicked()
{
      // e.g. casting to the class you know its connected with
    CButton* button = qobject_cast<CButton*>(sender());
    if( button != NULL )
    {
        AddCalcText(button->calcvalue);
    }
}
