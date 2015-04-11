#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "muparser/muparser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isEqual = false;

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    try
    {
        QString str = ui->textEdit->toPlainText();
        double fVal = str.toDouble();
        mu::Parser p;
        p.DefineVar("a", &fVal);
        p.SetExpr(ui->textEdit->toPlainText().toStdString());

        std::stringstream buffer;
        buffer << p.Eval();
        QString w = QString::fromStdString(buffer.str());
        SetCalcText(w);
        isEqual=true;
    }
    catch (mu::Parser::exception_type &e)
    {
        SetCalcText("");
    }
}

void MainWindow::on_pushButton_number0_clicked()
{
    AddCalcText("0");
}

void MainWindow::on_pushButton_number1_clicked()
{
    AddCalcText("1");
}

void MainWindow::on_pushButton_number2_clicked()
{
    AddCalcText("2");
}

void MainWindow::on_pushButton_number3_clicked()
{
    AddCalcText("3");
}

void MainWindow::on_pushButton_number4_clicked()
{
    AddCalcText("4");
}

void MainWindow::on_pushButton_number5_clicked()
{
    AddCalcText("5");
}

void MainWindow::on_pushButton_number6_clicked()
{
    AddCalcText("6");
}

void MainWindow::on_pushButton_number7_clicked()
{
    AddCalcText("7");
}

void MainWindow::on_pushButton_number8_clicked()
{
    AddCalcText("8");
}

void MainWindow::on_pushButton_number9_clicked()
{
    AddCalcText("9");
}

void MainWindow::on_pushButton_exp_plus_clicked()
{
    AddCalcText("+");
}

void MainWindow::on_pushButton_exp_minus_clicked()
{
    AddCalcText("-");
}

void MainWindow::on_pushButton_exp_mal_clicked()
{
    AddCalcText("*");
}

void MainWindow::on_pushButton_exp_geteilt_clicked()
{
    AddCalcText("/");
}

void MainWindow::on_pushButton_number_sin_clicked()
{
    AddCalcText("sin(");
}

void MainWindow::on_pushButton_number_cos_clicked()
{
    AddCalcText("cos(");
}

void MainWindow::on_pushButton_number_tan_clicked()
{
    AddCalcText("tan(");
}

void MainWindow::on_pushButton_number_sqrt_clicked()
{
    AddCalcText("sqrt(");
}

void MainWindow::on_pushButton_number_klauf_clicked()
{
    AddCalcText("(");
}

void MainWindow::on_pushButton_number_klzu_clicked()
{
    AddCalcText(")");
}

void MainWindow::on_pushButton_number_C_clicked()
{
    SetCalcText("");
}

void MainWindow::on_pushButton_number_CE_clicked()
{
    SetCalcText("");
}

void MainWindow::SetCalcText(QString txtstr)
{
    ui->textEdit->setText(txtstr);
}

void MainWindow::AddCalcText(QString txtstr)
{
    isEqual=false;
    if(isEqual)
    {
        isEqual=false;
        SetCalcText("");
        ui->textEdit->setText(txtstr);
    }
    else
    {
        ui->textEdit->setText(ui->textEdit->toPlainText()+txtstr);
    }
}
