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
#include <QTimer>
#include <QTextBrowser>



struct Paper
{
    QString title;
    QString author;
    QString publicTime;
    QString abstract;
    QString paperUrl;
    QString pdfUrl;
    Paper(QString title, QString author, QString publicTime, QString abstract, QString paperUrl, QString pdfUrl)
        : title(title), author(author), publicTime(publicTime), abstract(abstract), paperUrl(paperUrl), pdfUrl(pdfUrl) {}

    QString str() const
    {
        QString ret;
        ret = "Title: " + title + "\n\n" +
              "Author: " + author + "\n\n" +
              "Publication Time: " + publicTime + "\n\n" +
              "Abstract: " + abstract + "\n\n" +
              "Paper URL: " + paperUrl + "\n\n" +
              "PDF URL: " + pdfUrl;
        return ret;
    }

    QString toHtml() const
    {
        QString ret;
        ret = "<h1>" + title + "</h1>" +
              "<p><strong>作者：</strong> " + author + "</p>" +
              "<p><strong>发表时间：</strong> " + publicTime + "</p>" +
              "<p><strong>摘要:</strong> " + abstract + "</p>" +
              "<p><strong>文章链接：</strong> <a href=\"" + paperUrl + "\">" + paperUrl + "</a></p>" +
              "<p><strong>PDF下载：</strong> <a href=\"" + pdfUrl + "\">" + pdfUrl + "</a></p>";
        return ret;
    }
};


extern QNetworkAccessManager manager;
extern QString email;
QTimer dotTimerAI; //用来显示省略号的Timer
QTimer dotTimerSearch; //用来显示省略号的Timer
QTextEdit *lastAiTextEdit; //指向AI对话框的最后一个文本框

// 以下代码确保窗口可拖动
void MainWindow2::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragging = true;
        m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow2::mouseMoveEvent(QMouseEvent *event) {
    if (m_dragging && (event->buttons() & Qt::LeftButton)) {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

void MainWindow2::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragging = false;
        event->accept();
    }
}



QString qTextStyle = "QTextEdit {"
                           "background-color: rgb(255, 255, 255);" /* 设置背景颜色 */
                           "color: black;" /* 设置文本颜色 */
                           "border: 1px solid rgb(168, 85, 247);" /* 设置边框颜色 */
                           "padding: 4px 8px;" /* 设置内边距 */
                           "border-radius: 4px;" /* 设置圆角 */
                           "font-size: 14px;" /* 设置字体大小 */
                           "}"
                           "QTextEdit:focus {"
                           "border: 1px solid rgb(48, 5, 127);" /* 设置聚焦时的边框颜色 */
                           "}";


QString qScrollBarStyle = "/* ScrollBar */"
                              "QScrollBar:horizontal {"
                              "    border: none;"
                              "    background: #f0f0f0;"
                              "    height: 15px;"
                              "    margin: 0px 20px 0 20px;"
                              "}"
                              "QScrollBar:vertical {"
                              "    border: none;"
                              "    background: #f0f0f0;"
                              "    width: 15px;"
                              "    margin: 0px 0px 0px 0;"
                              "}"
                              "QScrollBar::handle:horizontal {"
                              "    background: rgb(168, 85, 247);"
                              "    min-width: 20px;"
                              "    border-radius: 7px;"
                              "}"
                              "QScrollBar::handle:vertical {"
                              "    background: rgb(168, 85, 247);"
                              "    min-height: 20px;"
                              "    border-radius: 7px;"
                              "}"
                              "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal,"
                              "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
                              "    border: none;"
                              "    background: none;"
                              "}"
                              "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal,"
                              "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                              "    background: none;"
                              "}";


QStringList MainWindow2::getAiHistory()
{
    QStringList strList;
    QString mainUrl = "http://62.234.28.172:5656/system/main/";
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


void MainWindow2::question_to_AI(QString question)
{
    // QStringList strList;
    QString mainUrl = "http://62.234.28.172:5656/system/main/";
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
        return;
    }

    QNetworkRequest aiQuestionRequest((QUrl(mainUrl)));
    aiQuestionRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    aiQuestionRequest.setRawHeader("Referer", mainUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("user_input", question);
    params.addQueryItem("submit_button", "get_airesult");
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    // qWarning()<<csrfToken;
    // qWarning()<<params.toString();
    QNetworkReply *aiQuestionReply = manager.post(aiQuestionRequest, params.query(QUrl::FullyEncoded).toUtf8());



    QEventLoop loop2;
    QObject::connect(aiQuestionReply, &QNetworkReply::finished, &loop2, &QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (aiQuestionReply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << aiQuestionReply->errorString();
        aiQuestionReply->deleteLater();
        return;
    }
    dotTimerAI.stop();
    this->on_pushButton_refreshAiHistory_clicked();
}



void MainWindow2::showDotAI()
{
    if(lastAiTextEdit->toPlainText() == "......")
    {
        lastAiTextEdit->setPlainText("");
    }
    lastAiTextEdit->insertPlainText(".");
}

void MainWindow2::showDotSearch()
{
    if(ui->pushButton_search->text() == "......")
    {
        ui->pushButton_search->setText("");
    }
    ui->pushButton_search->setText(ui->pushButton_search->text()+".");
}

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    // 窗口被创建
    ui->setupUi(this);
    // manager.post()
    ui->label_name->setText("当前用户："+email);
    on_pushButton_refreshAiHistory_clicked();

    // 设置固定窗口
    this->setFixedSize(1000, 650);
    // 隐藏标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);
    // 隐藏刷新按钮
    ui->pushButton_refreshAiHistory->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);

    //设置Timer
    QObject::connect(&dotTimerAI, &QTimer::timeout, this, &MainWindow2::showDotAI);
    QObject::connect(&dotTimerSearch, &QTimer::timeout, this, &MainWindow2::showDotSearch);
    //设置按钮的样式（读取哪个是选中滚动）
    this->on_stackedWidget_currentChanged();

    // 给语言选择框添加选项
    ui->comboBox_language->addItem("简体中文"); // Simplified Chinese
    ui->comboBox_language->addItem("繁体中文"); // Traditional Chinese
    ui->comboBox_language->addItem("英语");     // English
    ui->comboBox_language->addItem("西班牙语"); // Spanish
    ui->comboBox_language->addItem("阿拉伯语"); // Arabic
    ui->comboBox_language->addItem("法语");     // French
    ui->comboBox_language->addItem("德语");     // German
    ui->comboBox_language->addItem("葡萄牙语"); // Portuguese
    ui->comboBox_language->addItem("俄语");     // Russian
    ui->comboBox_language->addItem("日语");     // Japanese
    ui->comboBox_language->addItem("韩语");     // Korean
    ui->comboBox_language->addItem("意大利语"); // Italian
    ui->comboBox_language->addItem("荷兰语");   // Dutch
    ui->comboBox_language->addItem("希腊语");   // Greek
    ui->comboBox_language->addItem("波兰语");   // Polish
    ui->comboBox_language->addItem("瑞典语");   // Swedish
    ui->comboBox_language->addItem("土耳其语"); // Turkish
    ui->comboBox_language->addItem("希伯来语"); // Hebrew
    ui->comboBox_language->addItem("印地语");   // Hindi
    ui->comboBox_language->addItem("泰语");     // Thai
    ui->comboBox_language->addItem("越南语");   // Vietnamese

    ui->comboBox_language->setCurrentIndex(0);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}


void MainWindow2::displayHistory()
{
    ui->scrollArea_history->setWidgetResizable(true);

    // 创建内部widget和布局
    QWidget *scrollWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

    // 添加对话到布局中

    for(int i=0 ; i<history.size() ; i++)
    {

        layout->addWidget(new QLabel(i%2==0 ? "用户：" : "AI："));
        QTextEdit *textEdit = new QTextEdit();
        // 设置风格
        textEdit->setStyleSheet(qTextStyle);

        if(i == history.size()-1)
        {
            lastAiTextEdit = textEdit;
        }
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
        textEdit->setFixedHeight((h + 10 > 40 ? h + 10 : 40));
    }
    scrollWidget->setLayout(layout);
    ui->scrollArea_history->setWidget(scrollWidget);
    //滚动到最底部
    QScrollBar *vScrollBar = ui->scrollArea_history->verticalScrollBar();
    vScrollBar->setValue(vScrollBar->maximum());
    vScrollBar->setStyleSheet(qScrollBarStyle);
}

void MainWindow2::displaySearchResult(const QVector<Paper>& papers)
{
    ui->scrollArea_search->setWidgetResizable(true);

    // 创建内部widget和布局
    QWidget *scrollWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(scrollWidget);


    //没搜到
    if(papers.empty())
    {
        // layout->addWidget(new QLabel(i%2==0 ? "用户：" : "AI："));
        QTextBrowser *textEdit = new QTextBrowser();
        // QTextBrowser *textBrowser = new QTextBrowser;
        // 设置风格
        textEdit->setStyleSheet(qTextStyle);

        textEdit->setHtml("<h1>没有搜索到相关结果</h1>");
        textEdit->setOpenExternalLinks(true);
        // 不要滚动条
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        textEdit->setReadOnly(true); //只读
        //添加占位label
        layout->addWidget(textEdit);
        layout->addWidget(new QLabel(""));

        // 自适应高度
        textEdit->document()->adjustSize();
        textEdit->setFixedHeight(480);
    }

    // 添加到布局中
    for(int i=0 ; i<papers.size() ; i++)
    {

        // layout->addWidget(new QLabel(i%2==0 ? "用户：" : "AI："));
        QTextBrowser *textEdit = new QTextBrowser();
        // QTextBrowser *textBrowser = new QTextBrowser;
        // 设置风格
        textEdit->setStyleSheet(qTextStyle);

        textEdit->setHtml(papers[i].toHtml());
        textEdit->setOpenExternalLinks(true);
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
        textEdit->setFixedHeight((h + 10 > 40 ? h + 10 : 40));
    }
    scrollWidget->setLayout(layout);
    ui->scrollArea_search->setWidget(scrollWidget);
    //滚动到最底部
    QScrollBar *vScrollBar = ui->scrollArea_search->verticalScrollBar();
    // vScrollBar->setValue(vScrollBar->maximum());
    vScrollBar->setStyleSheet(qScrollBarStyle);
}

void MainWindow2::on_pushButton_refreshAiHistory_clicked()
{
    //从服务器获取搜索历史
    this->history = getAiHistory();
    displayHistory();
}

bool isSendingMessage;
void MainWindow2::on_pushButton_question_clicked()
{
    ui->pushButton_question->setDisabled(1);
    isSendingMessage = 1;
    QString question = ui->textEdit_question->toPlainText();
    ui->textEdit_question->clear();
    this->history.append(question);
    this->history.append("...");
    dotTimerAI.start(200);
    displayHistory();
    this->question_to_AI(question);



    if (!ui->textEdit_question->toPlainText().isEmpty())
        ui->pushButton_question->setEnabled(1);
    isSendingMessage = 0;
}


void MainWindow2::on_textEdit_question_textChanged()
{
    if (!ui->textEdit_question->toPlainText().isEmpty() && !isSendingMessage)
    {
        ui->pushButton_question->setEnabled(true);
    }
    else
    {
        ui->pushButton_question->setEnabled(false);
    }
}



void MainWindow2::on_pushButton_AI__chat_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow2::on_pushButton_Document_manage_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow2::on_pushButton_Document_query_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow2::on_pushButton_Mine_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

QVector<Paper> paperSearch(const QString &keyword)
{
    QVector<Paper> papers;
    QString searchUrl = "http://62.234.28.172:5656/system/paper_query/";
    QNetworkRequest request((QUrl(searchUrl)));

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
        return papers;
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
        return papers;
    }

    QNetworkRequest searchRequest((QUrl(searchUrl)));
    searchRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    searchRequest.setRawHeader("Referer", searchUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("query_input", keyword);
    params.addQueryItem("query_button", "get_paper_results");
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    // qWarning()<<csrfToken;
    // qWarning()<<params.toString();
    QNetworkReply *searchReply = manager.post(searchRequest, params.query(QUrl::FullyEncoded).toUtf8());



    QEventLoop loop2;
    QObject::connect(searchReply,&QNetworkReply::finished,&loop2,&QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (searchReply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << searchReply->errorString();
        searchReply->deleteLater();
        return papers;
    }

    // 读取响应内容
    QString html = searchReply->readAll();
    searchReply->deleteLater();

    // 取出有用的部分
    QString start_marker = "#*#*#*论文项目开始#*#*#*";
    QString end_marker = "#*#*#*论文项目结束#*#*#*";
    int start_pos = 0;

    while ((start_pos = html.indexOf(start_marker, start_pos)) != -1) {
        int end_pos = html.indexOf(end_marker, start_pos);
        if (end_pos == -1) break;

        // 匹配多个空格
        static QRegularExpression regExp("\\s+");

        QString project = html.mid(start_pos, end_pos - start_pos);
        start_pos = end_pos + end_marker.length();
        // 读取标题并整理格式
        QString title = project.mid(
            project.indexOf("#*#*#*标题开始#*#*#*") + 16,
            project.indexOf("#*#*#*标题结束#*#*#*") - project.indexOf("#*#*#*标题开始#*#*#*") - 16
            );
        title = title.remove('\n').trimmed().replace(regExp, " ");


        // 读取作者并整理格式
        QString author = project.mid(
            project.indexOf("#*#*#*作者开始#*#*#*") + 16,
            project.indexOf("#*#*#*作者结束#*#*#*") - project.indexOf("#*#*#*作者开始#*#*#*") - 16
            );
        author = author.remove('\n').trimmed().replace(regExp, " ");

        // 读取发布时间并整理格式
        QString publicTime = project.mid(
            project.indexOf("#*#*#*时间开始#*#*#*") + 16,
            project.indexOf("#*#*#*时间结束#*#*#*") - project.indexOf("#*#*#*时间开始#*#*#*") - 16
            );
        publicTime = publicTime.remove('\n').trimmed().replace(regExp, " ");

        // 读取摘要并整理格式
        QString abstractText = project.mid(
            project.indexOf("#*#*#*摘要开始#*#*#*") + 16,
            project.indexOf("#*#*#*摘要结束#*#*#*") - project.indexOf("#*#*#*摘要开始#*#*#*") - 16
            );
        abstractText = abstractText.remove('\n').trimmed().replace(regExp, " ");


        // 读取paperUrl并整理格式
        QString paperUrl = project.mid(
            project.indexOf("#*#*#*论文地址开始#*#*#*") + 18,
            project.indexOf("#*#*#*论文地址结束#*#*#*") - project.indexOf("#*#*#*论文地址开始#*#*#*") - 18
            );
        paperUrl = paperUrl.remove('\n').trimmed().replace(regExp, " ");

        // 读取pdfUrl并整理格式
        QString pdfUrl = project.mid(
            project.indexOf("#*#*#*pdf地址开始#*#*#*") + 19,
            project.indexOf("#*#*#*pdf地址结束#*#*#*") - project.indexOf("#*#*#*pdf地址开始#*#*#*") - 19
            );
        pdfUrl = pdfUrl.remove('\n').trimmed().replace(regExp, " ");

        // 新建 Paper 并将之加入返回的向量
        Paper newPaper(title, author, publicTime, abstractText, paperUrl, pdfUrl);
        papers.append(newPaper);

    }

    return papers;
}


void MainWindow2::on_pushButton_search_clicked()
{
    dotTimerSearch.start(200);
    auto originText = ui->pushButton_search->text();
    ui->pushButton_search->setText("");
    if(ui->pushButton_search->isEnabled()==false)
        return;
    ui->pushButton_search->setEnabled(false);
    auto searchResult = paperSearch(ui->lineEdit->text());
    displaySearchResult(searchResult);
    ui->pushButton_search->setEnabled(true);
    dotTimerSearch.stop();
    ui->pushButton_search->setText(originText);
}


void MainWindow2::on_pushButton_minimize_clicked()
{
    this->showMinimized();
}


void MainWindow2::on_pushButton_close_clicked()
{
    this->close();
}


void MainWindow2::on_stackedWidget_currentChanged()
{

    //顺序：文献 AI 翻译 搜索 任务 我的
    auto pureStyle = ui->pushButton_pure->styleSheet();
    auto selectedStyle = ui->pushButton_selected->styleSheet();

    // 隐藏两个模板按钮
    ui->pushButton_pure->setVisible(false);
    ui->pushButton_selected->setVisible(false);


    ui->pushButton_AI__chat_page->setStyleSheet(pureStyle);
    ui->pushButton_Document_manage_page->setStyleSheet(pureStyle);
    ui->pushButton_Document_query_page->setStyleSheet(pureStyle);
    ui->pushButton_Mine_page->setStyleSheet(pureStyle);
    ui->pushButton_task->setStyleSheet(pureStyle);
    ui->pushButton_translate_page->setStyleSheet(pureStyle);

    if(ui->stackedWidget->currentWidget() == ui->page_0_AI_chat)
    {
        ui->pushButton_AI__chat_page->setStyleSheet(selectedStyle);
    }

    if(ui->stackedWidget->currentWidget() == ui->page_1_Docu_mange)
    {
        ui->pushButton_Document_manage_page->setStyleSheet(selectedStyle);
    }

    if(ui->stackedWidget->currentWidget() == ui->page_2_Docu_query)
    {
        ui->pushButton_Document_query_page->setStyleSheet(selectedStyle);
    }

    if(ui->stackedWidget->currentWidget() == ui->page_3_mine)
    {
        ui->pushButton_Mine_page->setStyleSheet(selectedStyle);
    }



    //To be added
}


void MainWindow2::on_pushButton_translate_page_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4_translate);
}


void MainWindow2::on_textEdit_translate_textChanged()
{
    if(ui->textEdit->toPlainText()!=""&& !isSendingMessage)
    {
        ui->pushButton_translate->setEnabled(true);
    }
    else
    {
        ui->pushButton_translate->setEnabled(false);
    }
}


void MainWindow2::on_pushButton_translate_clicked()
{
    if(ui->pushButton_translate->isEnabled() == false)
    {
        return;
    }
    if(isSendingMessage == true)
    {
        QMessageBox::warning(nullptr, "翻译失败", "AI正在思考其他事情，请等待...");
        return;
    }
    auto textToTranslate = ui->textEdit_translate->toPlainText();
    auto originalAiText = ui->textEdit_question->toPlainText();

    ui->textEdit_question->setPlainText("请把以下内容翻译成"+ui->comboBox_language->currentText()+"\n\n\n"+textToTranslate);
    ui->stackedWidget->setCurrentWidget(ui->page_0_AI_chat);
    on_pushButton_question_clicked();

    ui->textEdit_question->setText(originalAiText);

}

