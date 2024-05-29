#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_returnPressed();

    void on_pushButton_3_clicked();

    void on_lineEdit_rPWconfirm_returnPressed();

    void on_lineEdit_rPW_returnPressed();

    void on_lineEdit_rEmail_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
