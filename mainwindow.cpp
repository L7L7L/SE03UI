#include "mainwindow.h"
#include "ui_mainwindow.h"
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

QNetworkAccessManager manager;

int login(const QString &loginUrl, const QString &email, const QString &password) {

    QNetworkRequest request((QUrl(loginUrl)));

    // 发送GET请求
    QNetworkReply *reply = manager.get(request);

    // 等待请求完成
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // 检查请求状态
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << reply->errorString();
        reply->deleteLater();
        return -1;
    }

    // 读取响应内容
    QString response = reply->readAll();
    reply->deleteLater();

    QString pattern = "<input\\s+type=\"hidden\"\\s+name=\"csrfmiddlewaretoken\"\\s+value=\"([^\"]*)\">";
    static QRegularExpression regex(pattern);

    // 匹配csrfToken
    QRegularExpressionMatch match = regex.match(response);
    QString csrfToken;
    if (match.hasMatch()) {
        csrfToken = match.captured();
        // std::cout<<csrfToken.toStdString()<<"\n";
        csrfToken = csrfToken.right(66);
        csrfToken = csrfToken.left(64);
        // std::cout<<csrfToken.toStdString()<<"\n";
    } else {
        return -1;
    }

    QNetworkRequest loginRequest((QUrl(loginUrl)));
    loginRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    loginRequest.setRawHeader("Referer", loginUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("email", email);
    params.addQueryItem("password", password);
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    // qWarning()<<csrfToken;
    // qWarning()<<params.toString();
    QNetworkReply *loginReply = manager.post(loginRequest, params.query(QUrl::FullyEncoded).toUtf8());

    QEventLoop loop2;
    QObject::connect(loginReply, &QNetworkReply::finished, &loop2, &QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (loginReply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << loginReply->errorString();
        loginReply->deleteLater();
        return -1;
    }

    // 读取响应内容
    QString loginResponse = loginReply->readAll();
    loginReply->deleteLater();
    // qWarning() << loginResponse.toStdString()<<"hhhh";
    if (loginResponse.contains("ThisTagMeansSuccessfullyLogin"))
    {
        return 1;
    }


    return 0;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString email = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    const QString loginURL = "http://62.234.28.172:8000/system/login/";

    if(email.isEmpty())
    {
        QMessageBox::warning(nullptr, "输入错误", "请输入用户名");
        return;
    }
    else if(password.isEmpty())
    {
        QMessageBox::warning(nullptr, "输入错误", "请输入密码");
        return;
    }
    ui->pushButton->setEnabled(false);
    auto originStyle = ui->pushButton->styleSheet();
    ui->pushButton->setStyleSheet("background-color : rgb(90, 90, 90);\ncolor : gray;\n\n");
    ui->pushButton->setText("登录中...");
    int loginStatus = login(loginURL, email, password);
    if(loginStatus == 1)
    {
        MainWindow2 *m = new MainWindow2;
        this->close();
        m->show();
    }
    else if(loginStatus == 0)
    {
        QMessageBox::warning(nullptr, "登录失败", "用户名或密码错误");
    }
    else if(loginStatus == -1)
    {
        QMessageBox::warning(nullptr, "登录失败", "网络异常");
    }
    ui->pushButton->setEnabled(true);
    ui->pushButton->setStyleSheet(originStyle);
    ui->pushButton->setText("登录");
}
