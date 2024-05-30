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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_refreshAiHistory;
    QTextEdit *textEdit_question;
    QPushButton *pushButton_question;
    QWidget *page_1_Docu_mange;
    QTextEdit *textEdit;
    QWidget *page_2_Docu_query;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_search;
    QLineEdit *lineEdit;
    QWidget *page_3_mine;
    QTextEdit *textEdit_3;
    QPushButton *pushButton_Document_manage_page;
    QPushButton *pushButton_AI__chat_page;
    QLabel *label_name;
    QPushButton *pushButton_Document_query_page;
    QPushButton *pushButton_translate;
    QPushButton *pushButton_Document_5;
    QPushButton *pushButton_Mine_page;
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
        stackedWidget->setGeometry(QRect(100, 30, 901, 700));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:#EEEEEE"));
        page_0_AI_chat = new QWidget();
        page_0_AI_chat->setObjectName("page_0_AI_chat");
        scrollArea = new QScrollArea(page_0_AI_chat);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 30, 791, 360));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 789, 358));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_refreshAiHistory = new QPushButton(page_0_AI_chat);
        pushButton_refreshAiHistory->setObjectName("pushButton_refreshAiHistory");
        pushButton_refreshAiHistory->setGeometry(QRect(830, 30, 51, 61));
        textEdit_question = new QTextEdit(page_0_AI_chat);
        textEdit_question->setObjectName("textEdit_question");
        textEdit_question->setGeometry(QRect(30, 410, 791, 131));
        textEdit_question->setStyleSheet(QString::fromUtf8("background-color : white\n"
""));
        pushButton_question = new QPushButton(page_0_AI_chat);
        pushButton_question->setObjectName("pushButton_question");
        pushButton_question->setEnabled(false);
        pushButton_question->setGeometry(QRect(840, 410, 31, 41));
        stackedWidget->addWidget(page_0_AI_chat);
        page_1_Docu_mange = new QWidget();
        page_1_Docu_mange->setObjectName("page_1_Docu_mange");
        textEdit = new QTextEdit(page_1_Docu_mange);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(450, 50, 104, 64));
        stackedWidget->addWidget(page_1_Docu_mange);
        page_2_Docu_query = new QWidget();
        page_2_Docu_query->setObjectName("page_2_Docu_query");
        textEdit_2 = new QTextEdit(page_2_Docu_query);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(260, 120, 104, 64));
        pushButton_search = new QPushButton(page_2_Docu_query);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(800, 10, 51, 21));
        lineEdit = new QLineEdit(page_2_Docu_query);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 10, 781, 21));
        stackedWidget->addWidget(page_2_Docu_query);
        page_3_mine = new QWidget();
        page_3_mine->setObjectName("page_3_mine");
        textEdit_3 = new QTextEdit(page_3_mine);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(110, 150, 104, 64));
        stackedWidget->addWidget(page_3_mine);
        pushButton_Document_manage_page = new QPushButton(centralwidget);
        pushButton_Document_manage_page->setObjectName("pushButton_Document_manage_page");
        pushButton_Document_manage_page->setGeometry(QRect(20, 40, 31, 31));
        pushButton_Document_manage_page->setStyleSheet(QString::fromUtf8(""));
        pushButton_AI__chat_page = new QPushButton(centralwidget);
        pushButton_AI__chat_page->setObjectName("pushButton_AI__chat_page");
        pushButton_AI__chat_page->setGeometry(QRect(20, 80, 31, 31));
        pushButton_AI__chat_page->setStyleSheet(QString::fromUtf8(""));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(760, 10, 131, 16));
        pushButton_Document_query_page = new QPushButton(centralwidget);
        pushButton_Document_query_page->setObjectName("pushButton_Document_query_page");
        pushButton_Document_query_page->setGeometry(QRect(20, 160, 31, 31));
        pushButton_Document_query_page->setStyleSheet(QString::fromUtf8(""));
        pushButton_translate = new QPushButton(centralwidget);
        pushButton_translate->setObjectName("pushButton_translate");
        pushButton_translate->setGeometry(QRect(20, 120, 31, 31));
        pushButton_translate->setStyleSheet(QString::fromUtf8(""));
        pushButton_Document_5 = new QPushButton(centralwidget);
        pushButton_Document_5->setObjectName("pushButton_Document_5");
        pushButton_Document_5->setGeometry(QRect(20, 200, 31, 31));
        pushButton_Document_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_Mine_page = new QPushButton(centralwidget);
        pushButton_Mine_page->setObjectName("pushButton_Mine_page");
        pushButton_Mine_page->setGeometry(QRect(20, 240, 31, 31));
        pushButton_Mine_page->setStyleSheet(QString::fromUtf8(""));
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
        pushButton_question->setText(QCoreApplication::translate("MainWindow2", "Q", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">doc</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">page_search</p>\n"
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
        pushButton_Document_manage_page->setText(QCoreApplication::translate("MainWindow2", "DOC", nullptr));
        pushButton_AI__chat_page->setText(QCoreApplication::translate("MainWindow2", "AI", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow2", "name", nullptr));
        pushButton_Document_query_page->setText(QCoreApplication::translate("MainWindow2", "Search", nullptr));
        pushButton_translate->setText(QCoreApplication::translate("MainWindow2", "Translate", nullptr));
        pushButton_Document_5->setText(QCoreApplication::translate("MainWindow2", "Task", nullptr));
        pushButton_Mine_page->setText(QCoreApplication::translate("MainWindow2", "Me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
