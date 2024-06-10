/********************************************************************************
** Form generated from reading UI file 'mainwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QScrollArea *scrollArea_docu_of_tag;
    QWidget *scrollAreaWidgetContents_4;
    QListWidget *listWidget_tag;
    QLabel *label_starTags;
    QLineEdit *lineEdit_tagKeyword;
    QPushButton *pushButton_tags;
    QLabel *label_staContent;
    QPushButton *pushButton_tagsFliter;
    QWidget *page_2_Docu_query;
    QPushButton *pushButton_search;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea_search;
    QWidget *scrollAreaWidgetContents_2;
    QComboBox *comboBox_field;
    QLabel *label_field;
    QLabel *label_sorttype;
    QComboBox *comboBox_sorttype;
    QComboBox *comboBox_sortorder;
    QLabel *label_sortorder;
    QPushButton *pushButton_last_pgae;
    QPushButton *pushButton_next_pgae;
    QLabel *label_of_searchpaper_num;
    QLineEdit *lineEdit_display_page;
    QWidget *page_3_mine;
    QLabel *label_name_2;
    QLabel *label_profile;
    QWidget *page_4_translate;
    QPushButton *pushButton_translate;
    QTextEdit *textEdit_translate;
    QComboBox *comboBox_language;
    QWidget *page_5_Daliy_push;
    QScrollArea *scrollArea_docu_of_push;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *label_Daily_push;
    QLabel *label_interested_field;
    QListWidget *listWidget_interested;
    QComboBox *comboBox_field_interested;
    QPushButton *pushButton_add_interested;
    QPushButton *pushButton_delete_interested;
    QPushButton *pushButton_refresh_push;
    QPushButton *pushButton_Document_manage_page;
    QPushButton *pushButton_AI__chat_page;
    QPushButton *pushButton_translate_page;
    QPushButton *pushButton_Mine_page;
    QLabel *label_3;
    QPushButton *pushButton_minimize;
    QPushButton *pushButton_close;
    QPushButton *pushButton_pure;
    QPushButton *pushButton_selected;
    QLabel *label_name;
    QLabel *label;
    QLabel *label_name_3;
    QPushButton *pushButton_Daily_push_page;
    QPushButton *pushButton_Document_query_page;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow2)
    {
        if (MainWindow2->objectName().isEmpty())
            MainWindow2->setObjectName("MainWindow2");
        MainWindow2->resize(1000, 650);
        MainWindow2->setStyleSheet(QString::fromUtf8("background-color:white;"));
        centralwidget = new QWidget(MainWindow2);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(130, 60, 901, 1031));
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
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border: 1px solid rgb(30, 90, 140); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
""));
        pushButton_question = new QPushButton(page_0_AI_chat);
        pushButton_question->setObjectName("pushButton_question");
        pushButton_question->setEnabled(false);
        pushButton_question->setGeometry(QRect(740, 530, 81, 31));
        pushButton_question->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(30, 90, 140); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231"
                        "\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: rgb(200, 200, 200); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: rgb(150, 150, 150); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
""));
        stackedWidget->addWidget(page_0_AI_chat);
        page_1_Docu_mange = new QWidget();
        page_1_Docu_mange->setObjectName("page_1_Docu_mange");
        scrollArea_docu_of_tag = new QScrollArea(page_1_Docu_mange);
        scrollArea_docu_of_tag->setObjectName("scrollArea_docu_of_tag");
        scrollArea_docu_of_tag->setGeometry(QRect(220, 40, 621, 501));
        scrollArea_docu_of_tag->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 619, 499));
        scrollArea_docu_of_tag->setWidget(scrollAreaWidgetContents_4);
        listWidget_tag = new QListWidget(page_1_Docu_mange);
        listWidget_tag->setObjectName("listWidget_tag");
        listWidget_tag->setGeometry(QRect(20, 40, 201, 421));
        listWidget_tag->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    background-color: transparent; /* \351\273\230\350\256\244\346\203\205\345\206\265\344\270\213\347\232\204\351\241\271\347\233\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    padding: 8px; /* \351\241\271\347\233\256\345\206\205\350\276\271\350\267\235 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: rgb(30, 90, 140); /* \351\200\211\344\270"
                        "\255\351\241\271\347\233\256\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \351\200\211\344\270\255\351\241\271\347\233\256\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: rgb(30, 90, 140); /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QScrollArea {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(168, 85, 247); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    backgro"
                        "und-color: rgb(240, 240, 240); /* \346\273\232\345\212\250\346\235\241\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    width: 12px; /* \346\273\232\345\212\250\346\235\241\345\256\275\345\272\246 */\n"
"    margin: 2px 0 2px 0; /* \346\273\232\345\212\250\346\235\241\344\270\216\345\206\205\345\256\271\351\227\264\347\232\204\351\227\264\350\267\235 */\n"
"    border-radius: 4px; /* \346\273\232\345\212\250\346\235\241\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: rgb(30, 90, 140); /* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227\351\242\234\350\211\262 */\n"
"    min-height: 20px; /* \346\273\221\345\235\227\346\234\200\345\260\217\351\253\230\345\272\246 */\n"
"    border-radius: 4px; /* \346\273\221\345\235\227\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:ver"
                        "tical {\n"
"    background: none;\n"
"}\n"
"\n"
""));
        label_starTags = new QLabel(page_1_Docu_mange);
        label_starTags->setObjectName("label_starTags");
        label_starTags->setGeometry(QRect(20, 10, 201, 31));
        label_starTags->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(70, 130, 180);\n"
"color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */"));
        label_starTags->setAlignment(Qt::AlignCenter);
        lineEdit_tagKeyword = new QLineEdit(page_1_Docu_mange);
        lineEdit_tagKeyword->setObjectName("lineEdit_tagKeyword");
        lineEdit_tagKeyword->setGeometry(QRect(20, 470, 121, 31));
        lineEdit_tagKeyword->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid rgb(30, 90, 140); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
""));
        pushButton_tags = new QPushButton(page_1_Docu_mange);
        pushButton_tags->setObjectName("pushButton_tags");
        pushButton_tags->setGeometry(QRect(20, 510, 191, 31));
        pushButton_tags->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(60, 120, 170); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(50, 110, 160); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346"
                        "\231\257\351\242\234\350\211\262 */\n"
"}\n"
""));
        label_staContent = new QLabel(page_1_Docu_mange);
        label_staContent->setObjectName("label_staContent");
        label_staContent->setGeometry(QRect(220, 10, 621, 31));
        label_staContent->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(30, 90, 140);\n"
"color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */"));
        label_staContent->setAlignment(Qt::AlignCenter);
        pushButton_tagsFliter = new QPushButton(page_1_Docu_mange);
        pushButton_tagsFliter->setObjectName("pushButton_tagsFliter");
        pushButton_tagsFliter->setGeometry(QRect(140, 470, 71, 31));
        pushButton_tagsFliter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(60, 120, 170); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(50, 110, 160); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346"
                        "\231\257\351\242\234\350\211\262 */\n"
"}\n"
""));
        stackedWidget->addWidget(page_1_Docu_mange);
        label_starTags->raise();
        scrollArea_docu_of_tag->raise();
        listWidget_tag->raise();
        lineEdit_tagKeyword->raise();
        pushButton_tags->raise();
        label_staContent->raise();
        pushButton_tagsFliter->raise();
        page_2_Docu_query = new QWidget();
        page_2_Docu_query->setObjectName("page_2_Docu_query");
        pushButton_search = new QPushButton(page_2_Docu_query);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(240, 10, 61, 31));
        pushButton_search->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(21, 64, 99); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231"
                        "\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: rgb(200, 200, 200); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: rgb(150, 150, 150); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
""));
        lineEdit = new QLineEdit(page_2_Docu_query);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 10, 221, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid rgb(30, 90, 140); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
""));
        scrollArea_search = new QScrollArea(page_2_Docu_query);
        scrollArea_search->setObjectName("scrollArea_search");
        scrollArea_search->setGeometry(QRect(20, 50, 821, 471));
        scrollArea_search->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 819, 469));
        scrollArea_search->setWidget(scrollAreaWidgetContents_2);
        comboBox_field = new QComboBox(page_2_Docu_query);
        comboBox_field->setObjectName("comboBox_field");
        comboBox_field->setGeometry(QRect(350, 10, 171, 31));
        comboBox_field->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 1px solid rgb(68, 5, 127); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
"\n"
""));
        label_field = new QLabel(page_2_Docu_query);
        label_field->setObjectName("label_field");
        label_field->setGeometry(QRect(310, 15, 31, 21));
        QFont font;
        font.setPointSize(10);
        label_field->setFont(font);
        label_field->setCursor(QCursor(Qt::PointingHandCursor));
        label_field->setTextFormat(Qt::PlainText);
        label_field->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_sorttype = new QLabel(page_2_Docu_query);
        label_sorttype->setObjectName("label_sorttype");
        label_sorttype->setGeometry(QRect(530, 15, 71, 21));
        label_sorttype->setFont(font);
        label_sorttype->setCursor(QCursor(Qt::PointingHandCursor));
        label_sorttype->setTextFormat(Qt::PlainText);
        label_sorttype->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBox_sorttype = new QComboBox(page_2_Docu_query);
        comboBox_sorttype->setObjectName("comboBox_sorttype");
        comboBox_sorttype->setGeometry(QRect(590, 10, 121, 31));
        comboBox_sorttype->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 1px solid rgb(68, 5, 127); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
"\n"
""));
        comboBox_sortorder = new QComboBox(page_2_Docu_query);
        comboBox_sortorder->setObjectName("comboBox_sortorder");
        comboBox_sortorder->setGeometry(QRect(780, 10, 61, 31));
        comboBox_sortorder->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 1px solid rgb(68, 5, 127); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
"\n"
""));
        label_sortorder = new QLabel(page_2_Docu_query);
        label_sortorder->setObjectName("label_sortorder");
        label_sortorder->setGeometry(QRect(720, 15, 51, 21));
        label_sortorder->setFont(font);
        label_sortorder->setCursor(QCursor(Qt::PointingHandCursor));
        label_sortorder->setTextFormat(Qt::PlainText);
        label_sortorder->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_last_pgae = new QPushButton(page_2_Docu_query);
        pushButton_last_pgae->setObjectName("pushButton_last_pgae");
        pushButton_last_pgae->setGeometry(QRect(670, 530, 40, 20));
        pushButton_last_pgae->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 10px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(21, 64, 99); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"    backg"
                        "round-color: rgb(200, 200, 200); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: rgb(150, 150, 150); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
""));
        pushButton_next_pgae = new QPushButton(page_2_Docu_query);
        pushButton_next_pgae->setObjectName("pushButton_next_pgae");
        pushButton_next_pgae->setGeometry(QRect(800, 530, 40, 20));
        pushButton_next_pgae->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 10px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(21, 64, 99); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"    backg"
                        "round-color: rgb(200, 200, 200); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: rgb(150, 150, 150); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
""));
        label_of_searchpaper_num = new QLabel(page_2_Docu_query);
        label_of_searchpaper_num->setObjectName("label_of_searchpaper_num");
        label_of_searchpaper_num->setGeometry(QRect(760, 530, 40, 20));
        lineEdit_display_page = new QLineEdit(page_2_Docu_query);
        lineEdit_display_page->setObjectName("lineEdit_display_page");
        lineEdit_display_page->setGeometry(QRect(720, 530, 31, 20));
        lineEdit_display_page->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid rgb(30, 90, 140); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
""));
        stackedWidget->addWidget(page_2_Docu_query);
        label_sortorder->raise();
        pushButton_search->raise();
        lineEdit->raise();
        label_field->raise();
        scrollArea_search->raise();
        label_sorttype->raise();
        comboBox_sorttype->raise();
        comboBox_sortorder->raise();
        comboBox_field->raise();
        pushButton_last_pgae->raise();
        pushButton_next_pgae->raise();
        label_of_searchpaper_num->raise();
        lineEdit_display_page->raise();
        page_3_mine = new QWidget();
        page_3_mine->setObjectName("page_3_mine");
        label_name_2 = new QLabel(page_3_mine);
        label_name_2->setObjectName("label_name_2");
        label_name_2->setGeometry(QRect(40, 70, 391, 21));
        label_name_2->setTextFormat(Qt::PlainText);
        label_name_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_profile = new QLabel(page_3_mine);
        label_profile->setObjectName("label_profile");
        label_profile->setGeometry(QRect(20, 40, 391, 21));
        label_profile->setTextFormat(Qt::PlainText);
        label_profile->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        stackedWidget->addWidget(page_3_mine);
        page_4_translate = new QWidget();
        page_4_translate->setObjectName("page_4_translate");
        pushButton_translate = new QPushButton(page_4_translate);
        pushButton_translate->setObjectName("pushButton_translate");
        pushButton_translate->setEnabled(false);
        pushButton_translate->setGeometry(QRect(760, 500, 81, 31));
        pushButton_translate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(21, 64, 99); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231"
                        "\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: rgb(200, 200, 200); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: rgb(150, 150, 150); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
""));
        textEdit_translate = new QTextEdit(page_4_translate);
        textEdit_translate->setObjectName("textEdit_translate");
        textEdit_translate->setGeometry(QRect(20, 30, 821, 451));
        textEdit_translate->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    border: 1px solid rgb(30, 90, 140); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
""));
        comboBox_language = new QComboBox(page_4_translate);
        comboBox_language->setObjectName("comboBox_language");
        comboBox_language->setGeometry(QRect(620, 500, 131, 31));
        comboBox_language->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 1px solid rgb(68, 5, 127); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
"\n"
""));
        stackedWidget->addWidget(page_4_translate);
        page_5_Daliy_push = new QWidget();
        page_5_Daliy_push->setObjectName("page_5_Daliy_push");
        scrollArea_docu_of_push = new QScrollArea(page_5_Daliy_push);
        scrollArea_docu_of_push->setObjectName("scrollArea_docu_of_push");
        scrollArea_docu_of_push->setGeometry(QRect(220, 40, 621, 501));
        scrollArea_docu_of_push->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 619, 499));
        scrollArea_docu_of_push->setWidget(scrollAreaWidgetContents_3);
        label_Daily_push = new QLabel(page_5_Daliy_push);
        label_Daily_push->setObjectName("label_Daily_push");
        label_Daily_push->setGeometry(QRect(220, 10, 621, 31));
        label_Daily_push->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(30, 90, 140);\n"
"color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */"));
        label_Daily_push->setAlignment(Qt::AlignCenter);
        label_interested_field = new QLabel(page_5_Daliy_push);
        label_interested_field->setObjectName("label_interested_field");
        label_interested_field->setGeometry(QRect(20, 10, 201, 31));
        label_interested_field->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(70, 130, 180);\n"
"color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */"));
        label_interested_field->setAlignment(Qt::AlignCenter);
        listWidget_interested = new QListWidget(page_5_Daliy_push);
        listWidget_interested->setObjectName("listWidget_interested");
        listWidget_interested->setGeometry(QRect(20, 40, 201, 341));
        listWidget_interested->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    background-color: transparent; /* \351\273\230\350\256\244\346\203\205\345\206\265\344\270\213\347\232\204\351\241\271\347\233\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    padding: 8px; /* \351\241\271\347\233\256\345\206\205\350\276\271\350\267\235 */\n"
"    border: none; /* \346\227\240\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: rgb(30, 90, 140); /* \351\200\211\344\270"
                        "\255\351\241\271\347\233\256\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \351\200\211\344\270\255\351\241\271\347\233\256\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: rgb(30, 90, 140); /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QScrollArea {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(168, 85, 247); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    backgro"
                        "und-color: rgb(240, 240, 240); /* \346\273\232\345\212\250\346\235\241\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    width: 12px; /* \346\273\232\345\212\250\346\235\241\345\256\275\345\272\246 */\n"
"    margin: 2px 0 2px 0; /* \346\273\232\345\212\250\346\235\241\344\270\216\345\206\205\345\256\271\351\227\264\347\232\204\351\227\264\350\267\235 */\n"
"    border-radius: 4px; /* \346\273\232\345\212\250\346\235\241\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: rgb(30, 90, 140); /* \346\273\232\345\212\250\346\235\241\346\273\221\345\235\227\351\242\234\350\211\262 */\n"
"    min-height: 20px; /* \346\273\221\345\235\227\346\234\200\345\260\217\351\253\230\345\272\246 */\n"
"    border-radius: 4px; /* \346\273\221\345\235\227\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:ver"
                        "tical {\n"
"    background: none;\n"
"}\n"
"\n"
""));
        comboBox_field_interested = new QComboBox(page_5_Daliy_push);
        comboBox_field_interested->setObjectName("comboBox_field_interested");
        comboBox_field_interested->setGeometry(QRect(20, 440, 121, 31));
        comboBox_field_interested->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: rgb(255, 255, 255); /* \350\256\276\347\275\256\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: black; /* \350\256\276\347\275\256\346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"    border: 1px solid rgb(70, 130, 180); /* \350\256\276\347\275\256\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"    padding: 4px 8px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 1px solid rgb(68, 5, 127); /* \350\256\276\347\275\256\350\201\232\347\204\246\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"}\n"
"\n"
""));
        pushButton_add_interested = new QPushButton(page_5_Daliy_push);
        pushButton_add_interested->setObjectName("pushButton_add_interested");
        pushButton_add_interested->setGeometry(QRect(150, 440, 61, 31));
        pushButton_add_interested->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_add_interested->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(21, 64, 99); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231"
                        "\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: rgb(200, 200, 200); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: rgb(150, 150, 150); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
""));
        pushButton_delete_interested = new QPushButton(page_5_Daliy_push);
        pushButton_delete_interested->setObjectName("pushButton_delete_interested");
        pushButton_delete_interested->setGeometry(QRect(20, 390, 191, 31));
        pushButton_delete_interested->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_delete_interested->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(21, 64, 99); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231"
                        "\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: rgb(200, 200, 200); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: rgb(150, 150, 150); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
""));
        pushButton_refresh_push = new QPushButton(page_5_Daliy_push);
        pushButton_refresh_push->setObjectName("pushButton_refresh_push");
        pushButton_refresh_push->setGeometry(QRect(20, 490, 191, 31));
        pushButton_refresh_push->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_refresh_push->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    border-radius: 4px; /* \350\256\276\347\275\256\345\234\206\350\247\222 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(21, 64, 99); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231"
                        "\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: rgb(200, 200, 200); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: rgb(150, 150, 150); /* \350\256\276\347\275\256\347\246\201\347\224\250\346\227\266\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
""));
        stackedWidget->addWidget(page_5_Daliy_push);
        pushButton_Document_manage_page = new QPushButton(centralwidget);
        pushButton_Document_manage_page->setObjectName("pushButton_Document_manage_page");
        pushButton_Document_manage_page->setGeometry(QRect(0, 130, 130, 51));
        QFont font1;
        pushButton_Document_manage_page->setFont(font1);
        pushButton_Document_manage_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Document_manage_page->setAutoFillBackground(false);
        pushButton_Document_manage_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(40, 100, 150); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(20, 80, 120); \n"
"}\n"
""));
        pushButton_AI__chat_page = new QPushButton(centralwidget);
        pushButton_AI__chat_page->setObjectName("pushButton_AI__chat_page");
        pushButton_AI__chat_page->setGeometry(QRect(0, 310, 130, 51));
        pushButton_AI__chat_page->setFont(font1);
        pushButton_AI__chat_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_AI__chat_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(40, 100, 150); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(20, 80, 120); \n"
"}\n"
""));
        pushButton_translate_page = new QPushButton(centralwidget);
        pushButton_translate_page->setObjectName("pushButton_translate_page");
        pushButton_translate_page->setGeometry(QRect(0, 370, 130, 51));
        pushButton_translate_page->setFont(font1);
        pushButton_translate_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_translate_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(40, 100, 150); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(20, 80, 120); \n"
"}\n"
""));
        pushButton_Mine_page = new QPushButton(centralwidget);
        pushButton_Mine_page->setObjectName("pushButton_Mine_page");
        pushButton_Mine_page->setGeometry(QRect(0, 430, 130, 51));
        pushButton_Mine_page->setFont(font1);
        pushButton_Mine_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Mine_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(40, 100, 150); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(20, 80, 120); \n"
"}\n"
""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, -10, 71, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/logo.png")));
        label_3->setScaledContents(true);
        label_3->setWordWrap(false);
        pushButton_minimize = new QPushButton(centralwidget);
        pushButton_minimize->setObjectName("pushButton_minimize");
        pushButton_minimize->setGeometry(QRect(940, 0, 31, 21));
        QFont font2;
        font2.setPointSize(22);
        font2.setStrikeOut(false);
        pushButton_minimize->setFont(font2);
        pushButton_minimize->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(30, 90, 140); /* \350\256\276\347\275\256\351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(24, 72, 112); /* \350\256\276\347\275\256\346\214\211\344\270\213\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
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
        pushButton_pure->setGeometry(QRect(0, 490, 130, 51));
        pushButton_pure->setFont(font1);
        pushButton_pure->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_pure->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(40, 100, 150); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(20, 80, 120); \n"
"}\n"
""));
        pushButton_selected = new QPushButton(centralwidget);
        pushButton_selected->setObjectName("pushButton_selected");
        pushButton_selected->setGeometry(QRect(0, 550, 130, 51));
        pushButton_selected->setFont(font1);
        pushButton_selected->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_selected->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(30, 90, 140); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(20, 60, 130); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(10, 80, 120); \n"
"}\n"
""));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(580, 40, 391, 21));
        label_name->setTextFormat(Qt::PlainText);
        label_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-10, 60, 141, 591));
        label->setStyleSheet(QString::fromUtf8("background-color:rgb(70, 130, 180)"));
        label_name_3 = new QLabel(centralwidget);
        label_name_3->setObjectName("label_name_3");
        label_name_3->setGeometry(QRect(510, 30, 91, 21));
        QFont font3;
        font3.setPointSize(14);
        label_name_3->setFont(font3);
        label_name_3->setTextFormat(Qt::PlainText);
        label_name_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_Daily_push_page = new QPushButton(centralwidget);
        pushButton_Daily_push_page->setObjectName("pushButton_Daily_push_page");
        pushButton_Daily_push_page->setGeometry(QRect(0, 190, 130, 51));
        pushButton_Daily_push_page->setFont(font1);
        pushButton_Daily_push_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Daily_push_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(40, 100, 150); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(20, 80, 120); \n"
"}\n"
""));
        pushButton_Document_query_page = new QPushButton(centralwidget);
        pushButton_Document_query_page->setObjectName("pushButton_Document_query_page");
        pushButton_Document_query_page->setGeometry(QRect(0, 250, 130, 51));
        pushButton_Document_query_page->setFont(font1);
        pushButton_Document_query_page->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_Document_query_page->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: rgb(70, 130, 180); /* \350\256\276\347\275\256\351\273\230\350\256\244\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \350\256\276\347\275\256\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    padding: 8px 16px; /* \350\256\276\347\275\256\345\206\205\350\276\271\350\267\235 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(40, 100, 150); \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgb(20, 80, 120); \n"
"}\n"
""));
        MainWindow2->setCentralWidget(centralwidget);
        label_3->raise();
        stackedWidget->raise();
        label->raise();
        pushButton_Document_manage_page->raise();
        pushButton_AI__chat_page->raise();
        pushButton_translate_page->raise();
        pushButton_Mine_page->raise();
        pushButton_minimize->raise();
        pushButton_close->raise();
        pushButton_pure->raise();
        pushButton_selected->raise();
        label_name->raise();
        label_name_3->raise();
        pushButton_Daily_push_page->raise();
        pushButton_Document_query_page->raise();
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 17));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName("statusbar");
        MainWindow2->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        label_3->setBuddy(label_3);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(scrollArea_history, pushButton_search);
        QWidget::setTabOrder(pushButton_search, pushButton_tagsFliter);
        QWidget::setTabOrder(pushButton_tagsFliter, scrollArea_search);
        QWidget::setTabOrder(scrollArea_search, comboBox_sorttype);
        QWidget::setTabOrder(comboBox_sorttype, lineEdit);
        QWidget::setTabOrder(lineEdit, listWidget_interested);
        QWidget::setTabOrder(listWidget_interested, scrollArea_docu_of_push);
        QWidget::setTabOrder(scrollArea_docu_of_push, pushButton_delete_interested);
        QWidget::setTabOrder(pushButton_delete_interested, comboBox_field);
        QWidget::setTabOrder(comboBox_field, comboBox_field_interested);
        QWidget::setTabOrder(comboBox_field_interested, pushButton_refresh_push);
        QWidget::setTabOrder(pushButton_refresh_push, pushButton_add_interested);
        QWidget::setTabOrder(pushButton_add_interested, comboBox_sortorder);
        QWidget::setTabOrder(comboBox_sortorder, pushButton_last_pgae);
        QWidget::setTabOrder(pushButton_last_pgae, pushButton_next_pgae);
        QWidget::setTabOrder(pushButton_next_pgae, lineEdit_display_page);
        QWidget::setTabOrder(lineEdit_display_page, pushButton_translate);
        QWidget::setTabOrder(pushButton_translate, textEdit_translate);
        QWidget::setTabOrder(textEdit_translate, comboBox_language);
        QWidget::setTabOrder(comboBox_language, pushButton_Document_manage_page);
        QWidget::setTabOrder(pushButton_Document_manage_page, pushButton_Daily_push_page);
        QWidget::setTabOrder(pushButton_Daily_push_page, pushButton_Document_query_page);
        QWidget::setTabOrder(pushButton_Document_query_page, pushButton_AI__chat_page);
        QWidget::setTabOrder(pushButton_AI__chat_page, pushButton_translate_page);
        QWidget::setTabOrder(pushButton_translate_page, pushButton_Mine_page);
        QWidget::setTabOrder(pushButton_Mine_page, pushButton_pure);
        QWidget::setTabOrder(pushButton_pure, pushButton_selected);
        QWidget::setTabOrder(pushButton_selected, textEdit_question);
        QWidget::setTabOrder(textEdit_question, scrollArea_docu_of_tag);
        QWidget::setTabOrder(scrollArea_docu_of_tag, pushButton_question);
        QWidget::setTabOrder(pushButton_question, pushButton_refreshAiHistory);
        QWidget::setTabOrder(pushButton_refreshAiHistory, listWidget_tag);
        QWidget::setTabOrder(listWidget_tag, pushButton_minimize);
        QWidget::setTabOrder(pushButton_minimize, pushButton_close);
        QWidget::setTabOrder(pushButton_close, lineEdit_tagKeyword);
        QWidget::setTabOrder(lineEdit_tagKeyword, pushButton_tags);

        retranslateUi(MainWindow2);

        stackedWidget->setCurrentIndex(1);
        comboBox_field->setCurrentIndex(-1);
        comboBox_sorttype->setCurrentIndex(-1);
        comboBox_sortorder->setCurrentIndex(-1);
        comboBox_language->setCurrentIndex(-1);
        comboBox_field_interested->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        pushButton_refreshAiHistory->setText(QCoreApplication::translate("MainWindow2", "\345\210\267\346\226\260", nullptr));
        textEdit_question->setPlaceholderText(QCoreApplication::translate("MainWindow2", "\347\273\231\342\200\235AI\342\200\234\345\217\221\346\266\210\346\201\257", nullptr));
        pushButton_question->setText(QCoreApplication::translate("MainWindow2", "\345\217\221\351\200\201", nullptr));
        label_starTags->setText(QCoreApplication::translate("MainWindow2", "\346\224\266\350\227\217\345\244\271", nullptr));
        lineEdit_tagKeyword->setText(QString());
        pushButton_tags->setText(QCoreApplication::translate("MainWindow2", "\346\270\205\351\231\244\347\255\233\351\200\211", nullptr));
        label_staContent->setText(QCoreApplication::translate("MainWindow2", "\345\206\205\345\256\271", nullptr));
        pushButton_tagsFliter->setText(QCoreApplication::translate("MainWindow2", "\347\255\233\351\200\211", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow2", "\346\220\234\347\264\242", nullptr));
        lineEdit->setText(QString());
        comboBox_field->setCurrentText(QString());
        comboBox_field->setPlaceholderText(QString());
        label_field->setText(QCoreApplication::translate("MainWindow2", "\351\242\206\345\237\237\357\274\232", nullptr));
        label_sorttype->setText(QCoreApplication::translate("MainWindow2", "\346\216\222\345\272\217\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox_sorttype->setCurrentText(QString());
        comboBox_sorttype->setPlaceholderText(QString());
        comboBox_sortorder->setCurrentText(QString());
        comboBox_sortorder->setPlaceholderText(QString());
        label_sortorder->setText(QCoreApplication::translate("MainWindow2", "\346\216\222\345\272\217\346\226\271\345\274\217\357\274\232", nullptr));
        pushButton_last_pgae->setText(QCoreApplication::translate("MainWindow2", "\344\270\212\344\270\200\351\241\265", nullptr));
        pushButton_next_pgae->setText(QCoreApplication::translate("MainWindow2", "\344\270\213\344\270\200\351\241\265", nullptr));
        label_of_searchpaper_num->setText(QCoreApplication::translate("MainWindow2", "/ 0 ", nullptr));
        lineEdit_display_page->setText(QCoreApplication::translate("MainWindow2", "0", nullptr));
        label_name_2->setText(QCoreApplication::translate("MainWindow2", "name", nullptr));
        label_profile->setText(QCoreApplication::translate("MainWindow2", "\346\210\221\347\232\204\344\277\241\346\201\257\357\274\232", nullptr));
        pushButton_translate->setText(QCoreApplication::translate("MainWindow2", "AI\347\277\273\350\257\221", nullptr));
        textEdit_translate->setPlaceholderText(QCoreApplication::translate("MainWindow2", "\350\276\223\345\205\245\350\246\201\347\277\273\350\257\221\347\232\204\345\206\205\345\256\271", nullptr));
        comboBox_language->setCurrentText(QString());
        comboBox_language->setPlaceholderText(QString());
        label_Daily_push->setText(QCoreApplication::translate("MainWindow2", "\346\216\250\350\215\220\346\226\207\347\214\256", nullptr));
        label_interested_field->setText(QCoreApplication::translate("MainWindow2", "\345\205\264\350\266\243\351\242\206\345\237\237", nullptr));
        comboBox_field_interested->setCurrentText(QString());
        comboBox_field_interested->setPlaceholderText(QString());
        pushButton_add_interested->setText(QCoreApplication::translate("MainWindow2", "\345\242\236\345\212\240", nullptr));
        pushButton_delete_interested->setText(QCoreApplication::translate("MainWindow2", "\345\210\240\351\231\244", nullptr));
        pushButton_refresh_push->setText(QCoreApplication::translate("MainWindow2", "\345\210\267\346\226\260\346\216\250\350\215\220", nullptr));
        pushButton_Document_manage_page->setText(QCoreApplication::translate("MainWindow2", "\346\226\207\347\214\256\347\256\241\347\220\206", nullptr));
        pushButton_AI__chat_page->setText(QCoreApplication::translate("MainWindow2", "AI\351\227\256\347\255\224", nullptr));
        pushButton_translate_page->setText(QCoreApplication::translate("MainWindow2", "\347\277\273\350\257\221", nullptr));
        pushButton_Mine_page->setText(QCoreApplication::translate("MainWindow2", "\346\210\221\347\232\204", nullptr));
        pushButton_minimize->setText(QCoreApplication::translate("MainWindow2", "-", nullptr));
        pushButton_close->setText(QCoreApplication::translate("MainWindow2", "X", nullptr));
        pushButton_pure->setText(QCoreApplication::translate("MainWindow2", "\345\216\237\345\247\213", nullptr));
        pushButton_selected->setText(QCoreApplication::translate("MainWindow2", "\351\200\211\344\270\255", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow2", "name", nullptr));
        label->setText(QString());
        label_name_3->setText(QCoreApplication::translate("MainWindow2", "\345\255\246\346\234\257\345\212\251\346\211\213", nullptr));
        pushButton_Daily_push_page->setText(QCoreApplication::translate("MainWindow2", "\346\226\207\347\214\256\346\216\250\350\215\220", nullptr));
        pushButton_Document_query_page->setText(QCoreApplication::translate("MainWindow2", "\346\226\207\347\214\256\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
