#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QStringListModel>

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

    void on_pushButton_number1_clicked();

    void on_pushButton_number2_clicked();

    void on_pushButton_number3_clicked();

    void on_pushButton_number4_clicked();

    void on_pushButton_number5_clicked();

    void on_pushButton_number6_clicked();

    void on_pushButton_number7_clicked();

    void on_pushButton_number8_clicked();

    void on_pushButton_number9_clicked();

    void on_pushButton_exp_plus_clicked();

    void on_pushButton_exp_minus_clicked();

    void on_pushButton_exp_mal_clicked();

    void on_pushButton_exp_geteilt_clicked();

    void on_pushButton_number_sin_clicked();

    void on_pushButton_number_cos_clicked();

    void on_pushButton_number_tan_clicked();

    void on_pushButton_number_sqrt_clicked();

    void on_pushButton_number_klauf_clicked();

    void on_pushButton_number_klzu_clicked();

    void on_pushButton_number_C_clicked();

    void on_pushButton_number_CE_clicked();

    void on_pushButton_number0_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QList<QString> history;
    void AddCalcText(QString txtstr);
    void SetCalcText(QString txtstr);
    QString Calculate(QString cStr);
    QStringListModel *model;
    bool isEqual;
};

#endif // MAINWINDOW_H
