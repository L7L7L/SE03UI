#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "url.h"
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
#include <QSettings>
#include <QFile>


QString email;
QNetworkAccessManager manager;

// 字符串加解密函数
QString encrypt(const QString &input) {
    QString key = "wangjincheng";
    QString output = input;
    int keyLength = key.length();
    for (int i = 0; i < input.length(); ++i) {
        output[i] = char(input[i].unicode() ^ key[i % keyLength].unicode());
    }
    return output;
}


// 以下代码确保窗口可拖动
void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (m_dragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragging = false;
        event->accept();
    }
}


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
    // 窗口被创建
    ui->setupUi(this);
    this->setFixedSize(370, 485);
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 读取记住的密码
    QString appDir = QCoreApplication::applicationDirPath();
    QString iniFilePath = appDir + "/SAconfig.ini";

    // 创建QSettings对象，指定ini文件路径
    QSettings settings(iniFilePath, QSettings::IniFormat);

    // 读取ini文件中的值，如果文件不存在，则返回默认值
    QString email = settings.value("Login/email", "").toString();
    QString password = settings.value("Login/password", "").toString();
    password = encrypt(password);
    QString remember = settings.value("Login/remember", "").toString();

    if(remember == "true"){
        ui->lineEdit->setText(email);
        ui->lineEdit_2->setText(password);
        ui->checkBox->setChecked(1);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->isEnabled()==false)
        return;
    QString tmpEmail = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    const QString loginURL = UrlofLogin;

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

        // 获取应用程序目录
        QString appDir = QCoreApplication::applicationDirPath();
        QString iniFilePath = appDir + "/SAconfig.ini";

        // 创建QSettings对象，指定ini文件路径
        QSettings settings(iniFilePath, QSettings::IniFormat);


        if(ui->checkBox->isChecked())// 记住密码
        {
            // 写入值到ini文件，如果文件不存在，则会创建该文件
            settings.setValue("Login/email", tmpEmail);
            settings.setValue("Login/password", encrypt(password));
            settings.setValue("Login/remember", "true");
        }
        else
        {
            settings.setValue("Login/remember", "false");
        }

        settings.sync();
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
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
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
    if(ui->pushButton_3->isEnabled()==false)
        return;

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

    const QString logonURL = UrlofLogon;
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


void MainWindow::on_pushButton_close_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_minimize_clicked()
{
    this->showMinimized();
}


void MainWindow::on_pushButton_forget_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_find);
}


void MainWindow::on_pushButton_back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
}


void MainWindow::on_pushButton_find_clicked()
{
    ui->pushButton_find->setEnabled(0);
    auto tmpEmail = ui->lineEdit_forget->text();

    if(tmpEmail.isEmpty())
    {
        QMessageBox::warning(nullptr, "找回失败", "请输入邮箱");
        ui->pushButton_find->setEnabled(1);
        return;
    }
    if(isValidEmail(tmpEmail) == false)
    {
        QMessageBox::warning(nullptr, "找回失败", "请输入合法的邮箱");
        ui->pushButton_find->setEnabled(1);
        return;
    }

    QNetworkRequest request((QUrl(UrlofForget)));

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
        QMessageBox::warning(nullptr, "找回失败", "网络错误");
        ui->pushButton_find->setEnabled(1);
        return;
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
        QMessageBox::warning(nullptr, "找回失败", "网络错误");
        ui->pushButton_find->setEnabled(1);
        return;
    }

    QNetworkRequest loginRequest((QUrl(UrlofForget)));
    loginRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QString UrlForget = UrlofForget;
    loginRequest.setRawHeader("Referer", UrlForget.toUtf8());

    QUrlQuery params;
    params.addQueryItem("email", tmpEmail);
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
        QMessageBox::warning(nullptr, "找回失败", "网络错误");
        ui->pushButton_find->setEnabled(1);
        return;
    }

    // 读取响应内容
    QString loginResponse = loginReply->readAll();
    loginReply->deleteLater();
    // qWarning() << loginResponse.toStdString()<<"hhhh";
    if (loginResponse.contains("密码已发送至您的邮箱。"))
    {
        QMessageBox::warning(nullptr, "找回成功", "密码已发送至您的邮箱，请查收");
        ui->pushButton_find->setEnabled(1);
        return;
    }
    else
    {
        QMessageBox::warning(nullptr, "找回失败", "该邮箱未注册");
        ui->pushButton_find->setEnabled(1);
        return;
    }
    ui->pushButton_find->setEnabled(1);
}

