#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow2.h"
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
#include <QUrlQuery>
#include <QHttpMultiPart>
#include <QNetworkCookieJar>
#include <QTextDocument>

extern QNetworkAccessManager manager;
extern QString email;

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    // manager.post()
    ui->label_name->setText(email);

}

MainWindow2::~MainWindow2()
{
    delete ui;
}
