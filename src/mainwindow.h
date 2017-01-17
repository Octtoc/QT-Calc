#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QStringListModel>
#include "stdafx.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_number_C_clicked();

    void on_pushButton_number_CE_clicked();

    void on_pushButton_enter_clicked();

    void on_pushButton_back_clicked();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;
    QList<QString> history;
    QString currentResult;
    QString Calculate(QString cStr);
    QStringListModel *model;
    bool isEqual;
    bool _enterPressed;

    void AddCalcText(QString txtstr);
    void RemoveCalcText(int from, int to);
    void setEnterPressed(bool enter);
    void PressCalcButton(QString text);
    void PressCalcButton(QString text, CalcButtonType type);
    bool getEnterPressed();
};

#endif // MAINWINDOW_H
