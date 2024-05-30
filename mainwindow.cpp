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
QString email;
QNetworkAccessManager manager;

int login(const QString &loginUrl, const QString &tmpEmail, const QString &password) {

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
    params.addQueryItem("email", tmpEmail);
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
        email = tmpEmail;
        return 1;
    }


    return 0;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(370, 455);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString tmpEmail = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    const QString loginURL = "http://62.234.28.172:8000/system/login/";

    if(tmpEmail.isEmpty())
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
    int loginStatus = login(loginURL, tmpEmail, password);
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

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_lineEdit_2_returnPressed()
{
    on_pushButton_clicked();
}


void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

int logon(const QString &logonUrl, const QString &tmpEmail, const QString &password)
{
    /*
        retrun -1 : Network error
        return 0 : email already exists
        return 1 : OK
    */
    QNetworkRequest request((QUrl(logonUrl)));

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

    QNetworkRequest logonRequest((QUrl(logonUrl)));
    logonRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    logonRequest.setRawHeader("Referer", logonUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("email", tmpEmail);
    params.addQueryItem("password", password);
    params.addQueryItem("confirm_password", password);
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    // qWarning()<<csrfToken;
    // qWarning()<<params.toString();
    QNetworkReply *loginReply = manager.post(logonRequest, params.query(QUrl::FullyEncoded).toUtf8());

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
    if (loginResponse.contains("ThisTagMeansLoginHtml"))
    {
        email = tmpEmail;
        return 1;
    }


    return 0;
}


bool isValidEmail(const QString &email) {
    // 定义用于验证邮箱的正则表达式
    static QRegularExpression emailPattern(R"((^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$))");

    // 使用正则表达式匹配邮箱地址
    QRegularExpressionMatch match = emailPattern.match(email);

    // 如果匹配成功，则邮箱地址合法

    return match.hasMatch();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString tmpEmail = ui->lineEdit_rEmail->text();
    QString password = ui->lineEdit_rPW->text();
    QString password2 = ui->lineEdit_rPWconfirm->text();
    if(tmpEmail.isEmpty())
    {
        QMessageBox::warning(nullptr, "注册失败", "请输入邮箱");
        return;
    }
    if(isValidEmail(tmpEmail) == false)
    {
        QMessageBox::warning(nullptr, "注册失败", "请输入合法的邮箱");
        return;
    }
    if(password.isEmpty())
    {
        QMessageBox::warning(nullptr, "注册失败", "请输入密码");
        return;
    }
    if(password2.isEmpty())
    {
        QMessageBox::warning(nullptr, "注册失败", "请输入确认密码");
        return;
    }
    else if(password != password2)
    {
        QMessageBox::warning(nullptr, "注册失败", "两次输入的密码不一致");
        return;
    }
    else if(ui->checkBox_2->isChecked() == false)
    {
        QMessageBox::warning(nullptr, "注册失败", "请阅读并接受用户协议");
        return;
    }
    ui->pushButton_3->setEnabled(false);
    auto originStyle = ui->pushButton_3->styleSheet();
    ui->pushButton_3->setStyleSheet("background-color : rgb(90, 90, 90);\ncolor : gray;\n\n");
    ui->pushButton_3->setText("注册中...");

    const QString logonURL = "http://62.234.28.172:8000/system/logon/";
    int status = logon(logonURL, tmpEmail, password);
    if(status == -1)
    {
        QMessageBox::warning(nullptr, "注册失败", "网络异常");
    }
    else if(status == 0)
    {
        QMessageBox::warning(nullptr, "注册失败", "该邮箱已被注册");
    }
    else if(status == 1)
    {
        QMessageBox::warning(nullptr, "注册成功", "注册成功，即将登陆");
        ui->lineEdit->setText(ui->lineEdit_rEmail->text());
        ui->lineEdit_2->setText(ui->lineEdit_rPW->text());
        on_pushButton_clicked();
    }
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_3->setStyleSheet(originStyle);
    ui->pushButton_3->setText("注册并登录");
}


void MainWindow::on_lineEdit_rPWconfirm_returnPressed()
{
    on_pushButton_3_clicked();
}


void MainWindow::on_lineEdit_rPW_returnPressed()
{
    on_pushButton_3_clicked();
}


void MainWindow::on_lineEdit_rEmail_returnPressed()
{
    on_pushButton_3_clicked();
}

