/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow2
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_0_AI_chat;
    QScrollArea *scrollArea_history;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_refreshAiHistory;
    QTextEdit *textEdit_question;
    QPushButton *pushButton_question;
    QWidget *page_1_Docu_mange;
    QTextEdit *textEdit;
    QWidget *page_2_Docu_query;
    QPushButton *pushButton_search;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea_search;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *page_3_mine;
    QTextEdit *textEdit_3;
    QPushButton *pushButton_Document_manage_page;
    QPushButton *pushButton_AI__chat_page;
    QPushButton *pushButton_Document_query_page;
    QPushButton *pushButton_translate;
    QPushButton *pushButton_task;
    QPushButton *pushButton_Mine_page;
    QLabel *label_3;
    QPushButton *pushButton_minimize;
    QPushButton *pushButton_close;
    QPushButton *pushButton_pure;
    QPushButton *pushButton_selected;
    QLabel *label_name;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName("MainWindow2");
        MainWindow2->resize(1000, 650);
        MainWindow2->setStyleSheet(QString::fromUtf8("background-color:white"));
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(130, 70, 901, 1031));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:#FAFAFA"));
        page_0_AI_chat = new QWidget();
        page_0_AI_chat->setObjectName("page_0_AI_chat");
        scrollArea_history = new QScrollArea(page_0_AI_chat);
        scrollArea_history->setObjectName("scrollArea_history");
        scrollArea_history->setGeometry(QRect(30, 30, 791, 391));
        scrollArea_history->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 789, 389));
        scrollArea_history->setWidget(scrollAreaWidgetContents);
        pushButton_refreshAiHistory = new QPushButton(page_0_AI_chat);
        pushButton_refreshAiHistory->setObjectName("pushButton_refreshAiHistory");
        pushButton_refreshAiHistory->setGeometry(QRect(830, 30, 51, 61));
        textEdit_question = new QTextEdit(page_0_AI_chat);
        textEdit_question->setObjectName("textEdit_question");
        textEdit_question->setGeometry(QRect(30, 440, 791, 81));
        textEdit_question->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(168, 85, 247); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border: 1px solid rgb(68, 5, 127); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
""));
        pushButton_question = new QPushButton(page_0_AI_chat);
        pushButton_question->setObjectName("pushButton_question");
        pushButton_question->setEnabled(false);
        pushButton_question->setGeometry(QRect(740, 530, 81, 31));
        pushButton_question->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(168, 85, 247); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346"
                        "\231\257\351\242\234\350\211\262 */\n"
"}\n"
""));
        stackedWidget->addWidget(page_0_AI_chat);
        page_1_Docu_mange = new QWidget();
        page_1_Docu_mange->setObjectName("page_1_Docu_mange");
        textEdit = new QTextEdit(page_1_Docu_mange);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(450, 50, 104, 64));
        stackedWidget->addWidget(page_1_Docu_mange);
        page_2_Docu_query = new QWidget();
        page_2_Docu_query->setObjectName("page_2_Docu_query");
        pushButton_search = new QPushButton(page_2_Docu_query);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(780, 10, 61, 31));
        pushButton_search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(168, 85, 247); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346"
                        "\231\257\351\242\234\350\211\262 */\n"
"}\n"
""));
        lineEdit = new QLineEdit(page_2_Docu_query);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 10, 761, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(168, 85, 247); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid rgb(68, 5, 147); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
""));
        scrollArea_search = new QScrollArea(page_2_Docu_query);
        scrollArea_search->setObjectName("scrollArea_search");
        scrollArea_search->setGeometry(QRect(20, 40, 821, 501));
        scrollArea_search->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 819, 499));
        scrollArea_search->setWidget(scrollAreaWidgetContents_2);
        stackedWidget->addWidget(page_2_Docu_query);
        page_3_mine = new QWidget();
        page_3_mine->setObjectName("page_3_mine");
        textEdit_3 = new QTextEdit(page_3_mine);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(110, 150, 104, 64));
        stackedWidget->addWidget(page_3_mine);
        pushButton_Document_manage_page = new QPushButton(centralwidget);
        pushButton_Document_manage_page->setObjectName("pushButton_Document_manage_page");
        pushButton_Document_manage_page->setGeometry(QRect(10, 110, 101, 51));
        QFont font;
        pushButton_Document_manage_page->setFont(font);
        pushButton_Document_manage_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Document_manage_page->setAutoFillBackground(false);
        pushButton_Document_manage_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(198, 125, 255); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
""));
        pushButton_AI__chat_page = new QPushButton(centralwidget);
        pushButton_AI__chat_page->setObjectName("pushButton_AI__chat_page");
        pushButton_AI__chat_page->setGeometry(QRect(10, 170, 101, 51));
        pushButton_AI__chat_page->setFont(font);
        pushButton_AI__chat_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_AI__chat_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(198, 125, 255); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); \n"
"}\n"
""));
        pushButton_Document_query_page = new QPushButton(centralwidget);
        pushButton_Document_query_page->setObjectName("pushButton_Document_query_page");
        pushButton_Document_query_page->setGeometry(QRect(10, 290, 101, 51));
        pushButton_Document_query_page->setFont(font);
        pushButton_Document_query_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Document_query_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(198, 125, 255); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); \n"
"}\n"
""));
        pushButton_translate = new QPushButton(centralwidget);
        pushButton_translate->setObjectName("pushButton_translate");
        pushButton_translate->setGeometry(QRect(10, 230, 101, 51));
        pushButton_translate->setFont(font);
        pushButton_translate->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_translate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(198, 125, 255); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); \n"
"}\n"
""));
        pushButton_task = new QPushButton(centralwidget);
        pushButton_task->setObjectName("pushButton_task");
        pushButton_task->setGeometry(QRect(10, 350, 101, 51));
        pushButton_task->setFont(font);
        pushButton_task->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_task->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(198, 125, 255); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); \n"
"}\n"
""));
        pushButton_Mine_page = new QPushButton(centralwidget);
        pushButton_Mine_page->setObjectName("pushButton_Mine_page");
        pushButton_Mine_page->setGeometry(QRect(10, 410, 101, 51));
        pushButton_Mine_page->setFont(font);
        pushButton_Mine_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Mine_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(198, 125, 255); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); \n"
"}\n"
""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 54, 54));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/logo.png")));
        label_3->setScaledContents(true);
        label_3->setWordWrap(false);
        pushButton_minimize = new QPushButton(centralwidget);
        pushButton_minimize->setObjectName("pushButton_minimize");
        pushButton_minimize->setGeometry(QRect(940, 0, 31, 21));
        QFont font1;
        font1.setPointSize(22);
        font1.setStrikeOut(false);
        pushButton_minimize->setFont(font1);
        pushButton_minimize->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(168, 85, 247); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
""));
        pushButton_close = new QPushButton(centralwidget);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setGeometry(QRect(970, 0, 31, 21));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(255, 85, 85);\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 4px;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgb(235, 65, 65);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(215, 45, 45);\n"
"}\n"
""));
        pushButton_pure = new QPushButton(centralwidget);
        pushButton_pure->setObjectName("pushButton_pure");
        pushButton_pure->setGeometry(QRect(10, 470, 101, 51));
        pushButton_pure->setFont(font);
        pushButton_pure->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_pure->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(198, 125, 255); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); \n"
"}\n"
""));
        pushButton_selected = new QPushButton(centralwidget);
        pushButton_selected->setObjectName("pushButton_selected");
        pushButton_selected->setGeometry(QRect(10, 530, 101, 51));
        pushButton_selected->setFont(font);
        pushButton_selected->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_selected->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(118, 25, 205); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(148, 65, 227); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(128, 45, 207); \n"
"}\n"
""));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(580, 40, 391, 21));
        label_name->setTextFormat(Qt::PlainText);
        label_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 17));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName("statusbar");
        MainWindow2->setStatusBar(statusbar);

        retranslateUi(MainWindow2);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        pushButton_refreshAiHistory->setText(QCoreApplication::translate("MainWindow2", "\345\210\267\346\226\260", nullptr));
        textEdit_question->setPlaceholderText(QCoreApplication::translate("MainWindow2", "\347\273\231\342\200\235AI\342\200\234\345\217\221\346\266\210\346\201\257", nullptr));
        pushButton_question->setText(QCoreApplication::translate("MainWindow2", "\345\217\221\351\200\201", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">doc</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow2", "\346\220\234\347\264\242", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow2", "fuck", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("MainWindow2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">page 3</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_Document_manage_page->setText(QCoreApplication::translate("MainWindow2", "\346\226\207\347\214\256\347\256\241\347\220\206", nullptr));
        pushButton_AI__chat_page->setText(QCoreApplication::translate("MainWindow2", "AI\351\227\256\347\255\224", nullptr));
        pushButton_Document_query_page->setText(QCoreApplication::translate("MainWindow2", "\346\220\234\347\264\242", nullptr));
        pushButton_translate->setText(QCoreApplication::translate("MainWindow2", "\347\277\273\350\257\221", nullptr));
        pushButton_task->setText(QCoreApplication::translate("MainWindow2", "\351\230\205\350\257\273\344\273\273\345\212\241", nullptr));
        pushButton_Mine_page->setText(QCoreApplication::translate("MainWindow2", "\346\210\221\347\232\204", nullptr));
        pushButton_minimize->setText(QCoreApplication::translate("MainWindow2", "-", nullptr));
        pushButton_close->setText(QCoreApplication::translate("MainWindow2", "X", nullptr));
        pushButton_pure->setText(QCoreApplication::translate("MainWindow2", "\345\216\237\345\247\213", nullptr));
        pushButton_selected->setText(QCoreApplication::translate("MainWindow2", "\351\200\211\344\270\255", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow2", "name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
