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
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QScrollBar>
extern QNetworkAccessManager manager;
extern QString email;



QStringList getAiHistory()
{
    QStringList strList;
    QString mainUrl = "http://62.234.28.172:8000/system/main/";
    QNetworkRequest request((QUrl(mainUrl)));

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
        return strList;
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
        return strList;
    }

    QNetworkRequest aiHistoryRequest((QUrl(mainUrl)));
    aiHistoryRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    aiHistoryRequest.setRawHeader("Referer", mainUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("user_input", "");
    params.addQueryItem("history_button", "get_history");
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    // qWarning()<<csrfToken;
    // qWarning()<<params.toString();
    QNetworkReply *aiHistoryReply = manager.post(aiHistoryRequest, params.query(QUrl::FullyEncoded).toUtf8());

    QEventLoop loop2;
    QObject::connect(aiHistoryReply, &QNetworkReply::finished, &loop2, &QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (aiHistoryReply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << aiHistoryReply->errorString();
        aiHistoryReply->deleteLater();
        return strList;
    }

    // 读取响应内容
    QString aiHistoryResponse = aiHistoryReply->readAll();
    aiHistoryReply->deleteLater();

    // 取出有用的部分
    QString startMarker = "#*#*提问历史开始#*#*";
    QString endMarker = "#*#*提问历史结束#*#*";

    int startIndex = aiHistoryResponse.indexOf(startMarker);
    int endIndex = aiHistoryResponse.indexOf(endMarker);

    if (startIndex != -1 && endIndex != -1 && startIndex < endIndex) {
        startIndex += startMarker.length(); // 移动到开始标记之后的位置
        aiHistoryResponse = aiHistoryResponse.mid(startIndex, endIndex - startIndex);
        // return extractedString;
    } else {
        qDebug() << "aiHistory未找到标记或标记顺序不正确";
        return strList;
    }

    strList = aiHistoryResponse.split("#*#*分割#*#*");

    strList.removeLast();


    return strList;
}



MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    // manager.post()
    ui->label_name->setText(email);
    on_pushButton_refreshAiHistory_clicked();
}

MainWindow2::~MainWindow2()
{
    delete ui;
}



void MainWindow2::on_pushButton_refreshAiHistory_clicked()
{
    ui->scrollArea->setWidgetResizable(true);
    //从服务器获取搜索历史
    auto history = getAiHistory();
    // 创建内部widget和布局
    QWidget *scrollWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

    // 添加对话到布局中

    for(int i=0 ; i<history.size() ; i++)
    {

        layout->addWidget(new QLabel(i%2==0 ? "用户：" : "AI："));
        QTextEdit *textEdit = new QTextEdit();
        textEdit->setPlainText(history[i]);
        // 不要滚动条
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        textEdit->setReadOnly(true); //只读
        //添加占位label
        layout->addWidget(textEdit);
        layout->addWidget(new QLabel(""));

        // 自适应高度
        textEdit->document()->adjustSize();
        auto h = textEdit->document()->size().height();
        textEdit->setFixedHeight((h > 20 ? h : 20));
    }
    scrollWidget->setLayout(layout);
    ui->scrollArea->setWidget(scrollWidget);
    //滚动到最底部
    QScrollBar *vScrollBar = ui->scrollArea->verticalScrollBar();
    vScrollBar->setValue(vScrollBar->maximum());

}


void MainWindow2::on_pushButton_question_clicked()
{

}

