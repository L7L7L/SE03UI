/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QWidget *stackedWidgetPage2;
    QStackedWidget *stackedWidget_2;
    QWidget *stackedWidgetPage1_2;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_4;
    QWidget *stackedWidgetPage2_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(370, 455);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 370, 455));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:white"));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName("stackedWidgetPage1");
        label_2 = new QLabel(stackedWidgetPage1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 180, 37, 20));
        pushButton = new QPushButton(stackedWidgetPage1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 310, 320, 36));
        pushButton->setStyleSheet(QString::fromUtf8("background-color : rgb(168, 85, 247);\n"
"color : white;\n"
"\n"
""));
        lineEdit_2 = new QLineEdit(stackedWidgetPage1);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(20, 220, 320, 40));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        checkBox = new QCheckBox(stackedWidgetPage1);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(20, 280, 81, 18));
        checkBox->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(stackedWidgetPage1);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 80, 37, 20));
        label_3 = new QLabel(stackedWidgetPage1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(145, 20, 82, 75));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/logo.png")));
        label_3->setScaledContents(true);
        label_3->setWordWrap(false);
        lineEdit = new QLineEdit(stackedWidgetPage1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 120, 319, 40));
        lineEdit->setMinimumSize(QSize(250, 40));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_2 = new QPushButton(stackedWidgetPage1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(239, 280, 101, 20));
        pushButton_2->setStyleSheet(QString::fromUtf8("border : none;\n"
"color : rgb(250, 143, 247)"));
        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName("stackedWidgetPage2");
        stackedWidget_2 = new QStackedWidget(stackedWidgetPage2);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 0, 370, 455));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("background-color:white"));
        stackedWidgetPage1_2 = new QWidget();
        stackedWidgetPage1_2->setObjectName("stackedWidgetPage1_2");
        label_4 = new QLabel(stackedWidgetPage1_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 180, 91, 20));
        pushButton_3 = new QPushButton(stackedWidgetPage1_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 310, 320, 36));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color : rgb(168, 85, 247);\n"
"color : white;\n"
"\n"
""));
        lineEdit_3 = new QLineEdit(stackedWidgetPage1_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(20, 220, 320, 40));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        lineEdit_3->setEchoMode(QLineEdit::Password);
        checkBox_2 = new QCheckBox(stackedWidgetPage1_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(20, 280, 101, 18));
        checkBox_2->setStyleSheet(QString::fromUtf8("color : rgb(250, 143, 247)"));
        label_5 = new QLabel(stackedWidgetPage1_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 80, 81, 20));
        label_6 = new QLabel(stackedWidgetPage1_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(145, 20, 82, 75));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/logo.png")));
        label_6->setScaledContents(true);
        label_6->setWordWrap(false);
        lineEdit_4 = new QLineEdit(stackedWidgetPage1_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(20, 120, 319, 40));
        lineEdit_4->setMinimumSize(QSize(250, 40));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_4 = new QPushButton(stackedWidgetPage1_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(239, 280, 101, 20));
        pushButton_4->setStyleSheet(QString::fromUtf8("border : none;\n"
"color : rgb(250, 143, 247)"));
        stackedWidget_2->addWidget(stackedWidgetPage1_2);
        stackedWidgetPage2_2 = new QWidget();
        stackedWidgetPage2_2->setObjectName("stackedWidgetPage2_2");
        stackedWidget_2->addWidget(stackedWidgetPage2_2);
        stackedWidget->addWidget(stackedWidgetPage2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 370, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\255\246\346\234\257\345\260\217\345\212\251\346\211\213-\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\202\256\347\256\261", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\350\277\230\346\262\241\346\234\211\350\264\246\346\210\267\357\274\237\346\263\250\345\206\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\264\246\346\210\267\345\257\206\347\240\201", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\345\271\266\347\231\273\345\275\225", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\264\246\346\210\267\345\257\206\347\240\201", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\227\347\224\250\346\210\267\345\215\217\350\256\256", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\347\224\250\351\202\256\347\256\261", nullptr));
        lineEdit_4->setText(QString());
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\263\250\345\206\214\351\202\256\347\256\261", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\267\262\346\234\211\350\264\246\346\210\267\357\274\237\347\231\273\345\275\225\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
