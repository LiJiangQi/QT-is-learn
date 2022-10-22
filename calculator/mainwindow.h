#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_multip_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_division_clicked();

    void on_pushButton_subtrac_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_bankspace_clicked();

    void on_pushButton_equal_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
