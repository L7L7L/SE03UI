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
#include <QtGui/QIcon>
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
    QLineEdit *lineEdit_rPW;
    QCheckBox *checkBox_2;
    QLabel *label_5;
    QLineEdit *lineEdit_rEmail;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_rPWconfirm;
    QLabel *label_7;
    QLabel *label_6;
    QWidget *stackedWidgetPage2_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(352, 442);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../AI.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(0, 0, 370, 455));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:white"));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName("stackedWidgetPage1");
        label_2 = new QLabel(stackedWidgetPage1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 200, 37, 20));
        pushButton = new QPushButton(stackedWidgetPage1);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 350, 320, 36));
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
        checkBox->setGeometry(QRect(20, 290, 81, 18));
        checkBox->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(stackedWidgetPage1);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 100, 37, 20));
        label_3 = new QLabel(stackedWidgetPage1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(145, 20, 80, 80));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/logo.png")));
        label_3->setScaledContents(true);
        label_3->setWordWrap(false);
        lineEdit = new QLineEdit(stackedWidgetPage1);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 130, 319, 40));
        lineEdit->setMinimumSize(QSize(250, 40));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_2 = new QPushButton(stackedWidgetPage1);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(239, 290, 101, 20));
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
        label_4->setGeometry(QRect(20, 170, 91, 20));
        pushButton_3 = new QPushButton(stackedWidgetPage1_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 360, 320, 36));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color : rgb(168, 85, 247);\n"
"color : white;\n"
"\n"
""));
        lineEdit_rPW = new QLineEdit(stackedWidgetPage1_2);
        lineEdit_rPW->setObjectName("lineEdit_rPW");
        lineEdit_rPW->setGeometry(QRect(20, 190, 320, 40));
        lineEdit_rPW->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        lineEdit_rPW->setEchoMode(QLineEdit::Password);
        checkBox_2 = new QCheckBox(stackedWidgetPage1_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(20, 330, 101, 18));
        checkBox_2->setStyleSheet(QString::fromUtf8("color : rgb(250, 143, 247)"));
        label_5 = new QLabel(stackedWidgetPage1_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 90, 81, 20));
        lineEdit_rEmail = new QLineEdit(stackedWidgetPage1_2);
        lineEdit_rEmail->setObjectName("lineEdit_rEmail");
        lineEdit_rEmail->setGeometry(QRect(20, 120, 319, 40));
        lineEdit_rEmail->setMinimumSize(QSize(250, 40));
        lineEdit_rEmail->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButton_4 = new QPushButton(stackedWidgetPage1_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(239, 330, 101, 20));
        pushButton_4->setStyleSheet(QString::fromUtf8("border : none;\n"
"color : rgb(250, 143, 247)"));
        lineEdit_rPWconfirm = new QLineEdit(stackedWidgetPage1_2);
        lineEdit_rPWconfirm->setObjectName("lineEdit_rPWconfirm");
        lineEdit_rPWconfirm->setGeometry(QRect(20, 260, 320, 40));
        lineEdit_rPWconfirm->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        lineEdit_rPWconfirm->setEchoMode(QLineEdit::Password);
        label_7 = new QLabel(stackedWidgetPage1_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 240, 91, 20));
        label_6 = new QLabel(stackedWidgetPage1_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(145, 20, 80, 80));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/image/logo.png")));
        label_6->setScaledContents(true);
        label_6->setWordWrap(false);
        stackedWidget_2->addWidget(stackedWidgetPage1_2);
        stackedWidgetPage2_2 = new QWidget();
        stackedWidgetPage2_2->setObjectName("stackedWidgetPage2_2");
        stackedWidget_2->addWidget(stackedWidgetPage2_2);
        stackedWidget->addWidget(stackedWidgetPage2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 352, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEdit_rEmail, lineEdit_rPW);
        QWidget::setTabOrder(lineEdit_rPW, lineEdit_rPWconfirm);
        QWidget::setTabOrder(lineEdit_rPWconfirm, checkBox_2);
        QWidget::setTabOrder(checkBox_2, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_3);
        QWidget::setTabOrder(pushButton_3, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, checkBox);
        QWidget::setTabOrder(checkBox, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\255\246\346\234\257\345\260\217\345\212\251\346\211\213-\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "password", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\202\256\347\256\261", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "123@qq.com", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\350\277\230\346\262\241\346\234\211\350\264\246\346\210\267\357\274\237\346\263\250\345\206\214", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\264\246\346\210\267\345\257\206\347\240\201", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\345\271\266\347\231\273\345\275\225", nullptr));
        lineEdit_rPW->setText(QString());
        lineEdit_rPW->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\264\246\346\210\267\345\257\206\347\240\201", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\227\347\224\250\346\210\267\345\215\217\350\256\256", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\347\224\250\351\202\256\347\256\261", nullptr));
        lineEdit_rEmail->setText(QString());
        lineEdit_rEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\263\250\345\206\214\351\202\256\347\256\261", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\267\262\346\234\211\350\264\246\346\210\267\357\274\237\347\231\273\345\275\225\357\274\201", nullptr));
        lineEdit_rPWconfirm->setText(QString());
        lineEdit_rPWconfirm->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
