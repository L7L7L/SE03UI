#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>

namespace Ui {
class MainWindow2;
}

struct Paper;

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
    void displayHistory();
    void displaySearchResult(const QVector<Paper>& papers);

private slots:

    void on_pushButton_refreshAiHistory_clicked();

    void on_pushButton_question_clicked();

    void on_textEdit_question_textChanged();

    void showDotAI();

    void showDotSearch();

    void on_pushButton_AI__chat_page_clicked();

    void on_pushButton_Document_manage_page_clicked();

    void on_pushButton_Document_query_page_clicked();

    void on_pushButton_Mine_page_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_minimize_clicked();

    void on_pushButton_close_clicked();

    void on_stackedWidget_currentChanged();

    void on_pushButton_translate_page_clicked();

    void on_textEdit_translate_textChanged();

    void on_pushButton_translate_clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow2 *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;
    QStringList history;
    QStringList getAiHistory();
    void question_to_AI(QString question);
};



#endif // MAINWINDOW2_H
