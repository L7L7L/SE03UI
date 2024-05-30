#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
    void display_history();

private slots:

    void on_pushButton_refreshAiHistory_clicked();

    void on_pushButton_question_clicked();

private:
    Ui::MainWindow2 *ui;
    QStringList history;
    QStringList getAiHistory();
    void question_to_AI(QString question);
};

#endif // MAINWINDOW2_H
