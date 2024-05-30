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
    QWidget *page;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_refreshAiHistory;
    QTextEdit *textEdit_question;
    QPushButton *pushButton_question;
    QWidget *page_2;
    QPushButton *pushButton_Document;
    QPushButton *pushButton_Document_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_name;
    QPushButton *pushButton_Document_3;
    QPushButton *pushButton_Document_4;
    QPushButton *pushButton_Document_5;
    QPushButton *pushButton_Document_6;
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
        page = new QWidget();
        page->setObjectName("page");
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 30, 791, 360));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 789, 358));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_refreshAiHistory = new QPushButton(page);
        pushButton_refreshAiHistory->setObjectName("pushButton_refreshAiHistory");
        pushButton_refreshAiHistory->setGeometry(QRect(830, 30, 51, 61));
        textEdit_question = new QTextEdit(page);
        textEdit_question->setObjectName("textEdit_question");
        textEdit_question->setGeometry(QRect(30, 410, 791, 131));
        textEdit_question->setStyleSheet(QString::fromUtf8("background-color : white\n"
""));
        pushButton_question = new QPushButton(page);
        pushButton_question->setObjectName("pushButton_question");
        pushButton_question->setEnabled(false);
        pushButton_question->setGeometry(QRect(840, 410, 31, 41));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        pushButton_Document = new QPushButton(centralwidget);
        pushButton_Document->setObjectName("pushButton_Document");
        pushButton_Document->setGeometry(QRect(20, 40, 31, 31));
        pushButton_Document->setStyleSheet(QString::fromUtf8(""));
        pushButton_Document_2 = new QPushButton(centralwidget);
        pushButton_Document_2->setObjectName("pushButton_Document_2");
        pushButton_Document_2->setGeometry(QRect(20, 80, 31, 31));
        pushButton_Document_2->setStyleSheet(QString::fromUtf8(""));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(100, 10, 551, 21));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(660, 10, 51, 21));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(760, 10, 131, 16));
        pushButton_Document_3 = new QPushButton(centralwidget);
        pushButton_Document_3->setObjectName("pushButton_Document_3");
        pushButton_Document_3->setGeometry(QRect(20, 160, 31, 31));
        pushButton_Document_3->setStyleSheet(QString::fromUtf8(""));
        pushButton_Document_4 = new QPushButton(centralwidget);
        pushButton_Document_4->setObjectName("pushButton_Document_4");
        pushButton_Document_4->setGeometry(QRect(20, 120, 31, 31));
        pushButton_Document_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_Document_5 = new QPushButton(centralwidget);
        pushButton_Document_5->setObjectName("pushButton_Document_5");
        pushButton_Document_5->setGeometry(QRect(20, 200, 31, 31));
        pushButton_Document_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_Document_6 = new QPushButton(centralwidget);
        pushButton_Document_6->setObjectName("pushButton_Document_6");
        pushButton_Document_6->setGeometry(QRect(20, 240, 31, 31));
        pushButton_Document_6->setStyleSheet(QString::fromUtf8(""));
        MainWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 17));
        MainWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow2);
        statusbar->setObjectName("statusbar");
        MainWindow2->setStatusBar(statusbar);

        retranslateUi(MainWindow2);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow2)
    {
        MainWindow2->setWindowTitle(QCoreApplication::translate("MainWindow2", "MainWindow", nullptr));
        pushButton_refreshAiHistory->setText(QCoreApplication::translate("MainWindow2", "\345\210\267\346\226\260", nullptr));
        textEdit_question->setPlaceholderText(QCoreApplication::translate("MainWindow2", "\347\273\231\342\200\235AI\342\200\234\345\217\221\346\266\210\346\201\257", nullptr));
        pushButton_question->setText(QCoreApplication::translate("MainWindow2", "Q", nullptr));
        pushButton_Document->setText(QCoreApplication::translate("MainWindow2", "DOC", nullptr));
        pushButton_Document_2->setText(QCoreApplication::translate("MainWindow2", "AI", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow2", "Search", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow2", "name", nullptr));
        pushButton_Document_3->setText(QCoreApplication::translate("MainWindow2", "Search", nullptr));
        pushButton_Document_4->setText(QCoreApplication::translate("MainWindow2", "Translate", nullptr));
        pushButton_Document_5->setText(QCoreApplication::translate("MainWindow2", "Task", nullptr));
        pushButton_Document_6->setText(QCoreApplication::translate("MainWindow2", "Me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow2: public Ui_MainWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
