#include "mainwindow2.h"
#include "ui_mainwindow2.h"
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
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QTimer>
#include <QTextBrowser>
#include <QMap>
#include <QDesktopServices>
#include <cmath>


extern QNetworkAccessManager manager;
extern QString email;
QTimer dotTimerAI; //用来显示省略号的Timer
QTimer dotTimerSearch; //用来显示省略号的Timer
QTextEdit *lastAiTextEdit; //指向AI对话框的最后一个文本框

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


QString qbuttonStyle = "QPushButton {"
                       "   font-size: 15px;"
                       "   color: black;"
                       "   border: 2px solid blue;"
                       "   border-radius: 10px;"
                       "   background-color: white;"
                       "}"
                       "QPushButton:focus {"
                       "   background-color: blue;"
                       "   color: white;"
                       "}";


MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    // 窗口被创建
    ui->setupUi(this);
    // manager.post()
    ui->label_name->setText("当前用户："+email);
    ui->label_name_2->setText("邮箱："+email);
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

    // 初始化领域列表和代码映射表
    initFieldMap();
    ui->comboBox_field->addItem("不限领域");
    QStringList subjects = {
        "K 理论与同调", "一般文学", "严格可解可积系统", "中尺度和纳米尺度物理学", "亚细胞突起",
        "交换代数", "交易与市场微观结构", "人工智能", "人机交互", "代数几何",
        "代数拓扑", "仪器和探测器", "优化和控制", "传统分析和微分方程", "信号处理",
        "信息检索", "信息理论", "偏微分方程分析", "元胞自动机与格子气体", "光学",
        "光谱理论", "其他凝聚态", "其他定量生物学", "其他统计学", "其他计算机科学",
        "几何拓扑学", "分子网络", "分布式、并行和集群计算", "功能分析", "加速器物理学",
        "动力系统", "化学物理", "医学物理学", "历史和概述", "原子和分子团簇",
        "原子物理学", "图像和视频处理", "图形", "地球与行星天体物理学", "地球物理学",
        "基因组学", "声音", "复杂变量", "多代理系统", "多媒体",
        "大众物理", "大气和海洋物理学", "天体物理", "天体物理学的仪器和方法", "太阳与恒星天体物理学",
        "子代数", "学习", "宇宙学与非规则天体物理学", "定量方法", "密码学与安全",
        "广义相对论和量子宇宙学", "应用", "应用物理学", "度量几何学", "强关联电子",
        "形式语言与自动机理论", "微分几何", "性能", "投资组合管理", "操作系统",
        "数值分析", "数字仓库", "数学物理", "数学软件", "数学金融",
        "数据分析、统计和概率", "数据库", "数据结构和算法", "数论", "新兴科技",
        "方法论", "无序系统与神经网络", "星系天体物理学", "普通数学", "普通物理",
        "机器人技术", "机器学习", "材料科学", "核理论", "核试验",
        "概率", "模式形成与孤子", "流体动力学", "混沌动力学", "点集拓扑学",
        "物理学与社会", "物理学的历史与哲学", "物理教育", "环与代数", "生物分子",
        "生物物理学", "电脑与社会", "硬件架构", "社会和信息网络", "神经元与认知",
        "神经和进化计算", "离散数学", "种群与进化", "空间物理学", "符号计算",
        "等离子体物理", "算子代数", "系统及控制", "组合数学", "组织和器官",
        "细胞行为", "经典物理学", "经济学", "统计力学", "统计学理论",
        "编程语言", "网络与互联网架构", "群论", "范畴理论", "表示论",
        "计算", "计算与语言", "计算几何", "计算复杂性", "计算工程，金融和科学",
        "计算机科学与博弈论", "计算机科学中的逻辑", "计算机视觉与模式识别", "计算物理学", "计量经济学",
        "证券定价", "财务概述", "超导现象", "软件工程", "软凝聚物",
        "辛几何", "适应与自组织系统", "逻辑", "量子气体", "量子物理学",
        "金融工程", "金融统计", "音频及语音处理", "风险管理", "高能天体物理现象",
        "高能物理-晶格", "高能物理-现象学", "高能物理实验", "高能物理理论"
    };
    ui->comboBox_field->addItems(subjects);
    ui->comboBox_field_interested->addItems(subjects);

    //初始化排序方式的列表框
    ui->comboBox_sorttype->addItem("按相关性");
    ui->comboBox_sorttype->addItem("按最后更新时间");
    ui->comboBox_sorttype->addItem("按发表时间");
    ui->comboBox_sorttype->setCurrentIndex(0);

    ui->comboBox_sortorder->addItem("升序");
    ui->comboBox_sortorder->addItem("降序");
    ui->comboBox_sortorder->setCurrentIndex(1);



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
    ui->pushButton_tags->setEnabled(0);

    //限制页数输入
    ui->lineEdit_display_page->setValidator(new QIntValidator(0, 0, ui->lineEdit_display_page));

}

MainWindow2::~MainWindow2()
{
    delete ui;
}


//刷新对话历史
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
    on_pushButton_tags_clicked();
}

void MainWindow2::on_pushButton_Document_query_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow2::on_pushButton_Mine_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow2::on_pushButton_translate_page_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4_translate);
}

void MainWindow2::on_pushButton_Daily_push_page_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    this->fresh_fields();
}

//文献搜索按钮
void MainWindow2::on_pushButton_search_clicked()
{
    dotTimerSearch.start(200);
    auto originText = ui->pushButton_search->text();
    ui->pushButton_search->setText("");
    if(ui->pushButton_search->isEnabled()==false)
        return;
    ui->pushButton_search->setEnabled(false);
    Paper_searchResult = paperSearch(ui->lineEdit->text(),
                                    mapField[ui->comboBox_field->currentText()],
                                    QString::number(ui->comboBox_sorttype->currentIndex()),
                                    QString::number(ui->comboBox_sortorder->currentIndex()));
    this->Page_searchResult_n=std::ceil(Paper_searchResult.size()/5.0);
    //限制页数输入
    ui->lineEdit_display_page->setValidator(new QIntValidator(0, this->Page_searchResult_n, ui->lineEdit_display_page));

    this->display_serchResult_n=1;
    displaySearchResult(Paper_searchResult.mid(0,5));
    this->ui->label_of_searchpaper_num->setText("/"+(QString::number(this->Page_searchResult_n)));
    this->ui->lineEdit_display_page->setText(QString::number(this->display_serchResult_n));
    ui->pushButton_search->setEnabled(true);
    dotTimerSearch.stop();
    ui->pushButton_search->setText(originText);
}


void MainWindow2::on_pushButton_last_pgae_clicked()
{
    if(this->display_serchResult_n<=1)
        return;

    display_serchResult_n--;
    displaySearchResult(Paper_searchResult.mid((display_serchResult_n-1)*5,5));
    this->ui->lineEdit_display_page->setText(QString::number(this->display_serchResult_n));
}

void MainWindow2::on_pushButton_next_pgae_clicked()
{
    if(this->display_serchResult_n>=this->Page_searchResult_n)
        return;

    display_serchResult_n++;
    displaySearchResult(Paper_searchResult.mid((display_serchResult_n-1)*5,5));
    this->ui->lineEdit_display_page->setText(QString::number(this->display_serchResult_n));
}

void MainWindow2::on_lineEdit_display_page_returnPressed()
{
    int n = ui->lineEdit_display_page->text().toInt();
    if(n<1 || n>this->Page_searchResult_n)
        return;
    this->display_serchResult_n=n;
    displaySearchResult(Paper_searchResult.mid((display_serchResult_n-1)*5,5));
    this->ui->lineEdit_display_page->setText(QString::number(this->display_serchResult_n));
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
    ui->pushButton_Daily_push_page->setStyleSheet(pureStyle);
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

    if(ui->stackedWidget->currentWidget() == ui->page_4_translate)
    {
        ui->pushButton_translate_page->setStyleSheet(selectedStyle);
    }

    if(ui->stackedWidget->currentWidget() == ui->page_5_Daliy_push)
    {
        ui->pushButton_Daily_push_page->setStyleSheet(selectedStyle);
    }

    //To be added
}



void MainWindow2::on_textEdit_translate_textChanged()
{
    if(ui->textEdit_translate->toPlainText()!=""&& !isSendingMessage)
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

//以下函数用于显示动态...
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

void MainWindow2::on_lineEdit_returnPressed()
{
    on_pushButton_search_clicked();
}


//获取ai对话历史
QStringList MainWindow2::getAiHistory()
{
    QStringList strList;
    QString mainUrl = UrlofMain;
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
//传输用户提问至后端
void MainWindow2::question_to_AI(QString question)
{
    // QStringList strList;
    QString mainUrl = UrlofMain;
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
//渲染ai对话历史
void MainWindow2::displayHistory()
{
    ui->scrollArea_history->setWidgetResizable(true);

    // 创建内部widget和布局
    QWidget *scrollWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(scrollWidget);

    // 添加对话到布局中

    for(int i=0 ; i<history.size() ; i++)
    {
        QLabel* labelTalker = new QLabel(i%2==0 ? "用户" : "AI");
        QFont font;
        font.setFamily("微软雅黑");  // 设置字体族
        font.setPointSize(20);    // 设置字体大小
        font.setBold(true);       // 设置粗体
        labelTalker->setFont(font);
        if(i%2==0)
        {
            labelTalker->setAlignment(Qt::AlignRight);
        }
        layout->addWidget(labelTalker);

        QTextEdit *textEdit = new QTextEdit();
        // 设置风格
        textEdit->setStyleSheet(qTextStyle);

        if(i == history.size()-1)
        {
            lastAiTextEdit = textEdit;
        }
        history[i].replace("\n", "<br>");
        textEdit->setHtml(history[i]);
        // 不要滚动条
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        textEdit->setReadOnly(true); //只读




        if(i%2==0)
        {
            // 创建一个水平布局用于放置 textEdit
            QHBoxLayout *hLayout = new QHBoxLayout();
            hLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
            hLayout->addWidget(textEdit);
            // 将水平布局添加到主垂直布局中
            layout->addLayout(hLayout);
        }
        else
        {
            layout->addWidget(textEdit);
        }
        //添加占位label
        layout->addWidget(new QLabel(""));

        // 自适应高度
        textEdit->document()->adjustSize();
        auto h = textEdit->document()->size().height();
        // auto w = textEdit->document()->size().width();
        textEdit->setFixedHeight(h+10);
        textEdit->setFixedWidth(600);
    }
    scrollWidget->setLayout(layout);
    ui->scrollArea_history->setWidget(scrollWidget);
    //滚动到最底部
    QScrollBar *vScrollBar = ui->scrollArea_history->verticalScrollBar();
    vScrollBar->setValue(vScrollBar->maximum());
    vScrollBar->setStyleSheet(qScrollBarStyle);
}



//获取论文查询结果
QVector<Paper> MainWindow2::paperSearch(const QString &keyword, const QString &field, const QString &sortType, const QString &sortOrder)
{
    QVector<Paper> papers;
    QString searchUrl = UrlofQuery;
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
    params.addQueryItem("field_input", field);
    params.addQueryItem("sort_type_input", sortType);
    params.addQueryItem("sort_order_input", sortOrder);
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

        int start = project.indexOf("#*#*#*已收藏标签开始#*#*#*");
        int end = project.indexOf("#*#*#*已收藏标签结束#*#*#*");
        if(start!=-1 && end!=-1 && start < end)
        {
            QString startag = project.mid(start+19,end-19-start);
            startag = startag.remove('\n').trimmed().replace(regExp, " ");
            // 新建 Paper 并将之加入返回的向量
            Paper newPaper(title, author, publicTime, abstractText, paperUrl, pdfUrl,startag);
            papers.append(newPaper);
        }
        else
        {
            // 新建 Paper 并将之加入返回的向量
            Paper newPaper(title, author, publicTime, abstractText, paperUrl, pdfUrl);
            papers.append(newPaper);
        }
    }

    return papers;
}

//收藏文献
void MainWindow2::starPaper(QString paperUrl, QComboBox* tagBox, QPushButton* button)
{
    QString originalText = button->text();
    button->setText("收藏中");
    button->setEnabled(0);
    QString searchUrl = UrlofQuery;
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
        button->setText(originalText);
        button->setEnabled(0);
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
        button->setText(originalText);
        button->setEnabled(1);
        return;
    }

    QNetworkRequest aiQuestionRequest((QUrl(searchUrl)));
    aiQuestionRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    aiQuestionRequest.setRawHeader("Referer", searchUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("entry_id", paperUrl);
    params.addQueryItem("collect_button", "collect_paper");
    params.addQueryItem("tag_input", tagBox->currentText());
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    // qWarning()<<csrfToken;
    // qWarning()<<params.toString();
    QNetworkReply *starQuestionReply = manager.post(aiQuestionRequest, params.query(QUrl::FullyEncoded).toUtf8());

    QEventLoop loop2;
    QObject::connect(starQuestionReply, &QNetworkReply::finished, &loop2, &QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (starQuestionReply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << starQuestionReply->errorString();
        starQuestionReply->deleteLater();
        button->setText(originalText);
        button->setEnabled(1);
        return;
    }
    button->setText("√ 已收藏");
    QTimer::singleShot(3000, [button, originalText]() {
        button->setText(originalText);
        button->setEnabled(1);
    });
    //刷新收藏夹
    on_pushButton_tags_clicked();
}

//渲染搜索结果
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

    QStringList Tags = getTags();

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
        //添加到布局中
        layout->addWidget(textEdit);


        // 自适应高度
        textEdit->document()->adjustSize();
        auto h = textEdit->document()->size().height();
        textEdit->setFixedHeight(h);

        QHBoxLayout *layoutH = new QHBoxLayout;
        auto paperUrl = papers[i].paperUrl;

        if(papers[i].is_star)
        {
            QLabel *tag_label = new QLabel("已收藏到："+papers[i].starTag);
            tag_label->setStyleSheet("background-color: rgb(168, 85, 247);color: white;  border: none; padding: 8px 16px;  border-radius: 4px;font-size: 14px;" );
            layoutH->addWidget(tag_label);
        }
        else
        {
            //标签选择框
            layoutH->addWidget(new QLabel(" 选择 / 输入一个标签："));
            QComboBox *tagCombo = new QComboBox();


            //收藏按钮
            QPushButton *buttonStar = new QPushButton("收藏此文章");
            buttonStar->setStyleSheet(ui->pushButton_search->styleSheet());
            connect(buttonStar, &QPushButton::clicked, [this, paperUrl, tagCombo, buttonStar]() { starPaper(paperUrl,tagCombo, buttonStar); });

            tagCombo->setEditable(true);
            tagCombo->setStyleSheet(ui->comboBox_field->styleSheet());
            tagCombo->addItems(Tags);
            layoutH->addWidget(tagCombo);
            layoutH->addWidget(buttonStar);
        }

        //下载按钮
        QPushButton *buttonPdf = new QPushButton("下载pdf");
        buttonPdf->setStyleSheet(ui->pushButton_search->styleSheet());
        auto pdfUrl = papers[i].pdfUrl;
        connect(buttonPdf, &QPushButton::clicked, [pdfUrl]() { QDesktopServices::openUrl(pdfUrl); });

        //原文链接按钮
        QPushButton *buttonLink = new QPushButton("打开原文链接");
        buttonLink->setStyleSheet(ui->pushButton_search->styleSheet());
        connect(buttonLink, &QPushButton::clicked, [ paperUrl]() { QDesktopServices::openUrl(paperUrl); });

        //添加空间到布局中
        layout->addLayout(layoutH);




        layoutH->addWidget(new QLabel(" "));
        layoutH->addWidget(buttonPdf);
        layoutH->addWidget(buttonLink);
        //添加占位label
        layout->addWidget(new QLabel("\n\n"));

    }
    scrollWidget->setLayout(layout);
    ui->scrollArea_search->setWidget(scrollWidget);
    //滚动到最底部
    QScrollBar *vScrollBar = ui->scrollArea_search->verticalScrollBar();
    // vScrollBar->setValue(vScrollBar->maximum());
    vScrollBar->setStyleSheet(qScrollBarStyle);
}


//获取收藏夹
QStringList MainWindow2::getTags()
{
    QStringList TagList;
    QString mainUrl = UrlofStar;
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
        return TagList;
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
        return TagList;
    }

    QNetworkRequest TagsRequest((QUrl(mainUrl)));
    TagsRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    TagsRequest.setRawHeader("Referer", mainUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("get_all_star_tag_button", "get_all_star_tag");
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    // qWarning()<<csrfToken;
    // qWarning()<<params.toString();
    QNetworkReply *TagsReply = manager.post(TagsRequest, params.query(QUrl::FullyEncoded).toUtf8());



    QEventLoop loop2;
    QObject::connect(TagsReply, &QNetworkReply::finished, &loop2, &QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (TagsReply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << TagsReply->errorString();
        TagsReply->deleteLater();
        return TagList;
    }

    // 读取响应内容
    QString TagsResponse = TagsReply->readAll();
    TagsReply->deleteLater();

    // 取出有用的部分
    QString startMarker = "*#*#*# 标签开始 *#*#*#";
    QString endMarker = "*#*#*# 标签结束 *#*#*#";

    int startIndex = TagsResponse.indexOf(startMarker);
    int endIndex = TagsResponse.indexOf(endMarker);

    if (startIndex != -1 && endIndex != -1 && startIndex < endIndex) {
        startIndex += startMarker.length(); // 移动到开始标记之后的位置
        TagsResponse = TagsResponse.mid(startIndex, endIndex - startIndex);
    } else {
        qDebug() << "Tag未找到标记或标记顺序不正确";
        return TagList;
    }

    QStringList rawTags = TagsResponse.split("*#*#");
    static QRegularExpression regExp("\\s+");
    for (QString tag : rawTags)
    {
        tag=tag.remove('\n').trimmed().replace(regExp," ");
        if(tag!="")
        {
            TagList.append(tag);  // 修剪标签并添加到 TagList 中
        }
    }

    return TagList;
}
//渲染收藏夹
void MainWindow2::display_tags(QStringList &TagList)
{
    ui->listWidget_tag->clear();
    ui->listWidget_tag->addItems(TagList);
    if(!TagList.empty())
    {
        ui->listWidget_tag->setCurrentRow(0);
    }

    //QScrollBar *scrollBar = new QScrollBar(Qt::Vertical, this);
    //scrollBar->setStyleSheet(qScrollBarStyle);


    //->listWidget_tag->addScrollBarWidget(scrollBar, Qt::AlignRight);
    //创建内部widget和布局
    QWidget *scrollWidget = new QWidget;
    QVBoxLayout * layout = new QVBoxLayout(scrollWidget);
    for (auto it: TagList)
    {
        qWarning()<<it;
    }
    if(TagList.empty())
    {
        QTextBrowser *textEdit = new QTextBrowser();
        textEdit->setStyleSheet(qTextStyle);
        textEdit->setHtml("<h1>网络链接故障</h1>");
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
        textEdit->setFixedHeight(100);
    }

    scrollWidget->setLayout(layout);
}

void MainWindow2::on_pushButton_tags_clicked()
{
    ui->pushButton_tags->setEnabled(0);
    QStringList Tag = this->getTags();
    this->display_tags(Tag);
    ui->pushButton_tags->setEnabled(1);
}

//获取收藏夹所含论文
void MainWindow2::get_Docu_of_tag(QString tag)
{
    QVector<Paper> papers;
    QString searchUrl = UrlofStar;
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

    QNetworkRequest searchRequest((QUrl(searchUrl)));
    searchRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    searchRequest.setRawHeader("Referer", searchUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("star_query_input", tag);
    params.addQueryItem("star_query_button", "get_star_type_results");
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
        return;
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
    this->now_tag=tag;
    display_Docu_of_tag(papers);
    return;
}
//渲染收藏夹所含论文
void MainWindow2::display_Docu_of_tag(QVector<Paper> &papers)
{
    ui->scrollArea_docu_of_tag->setWidgetResizable(true);

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

        textEdit->setHtml("<h1>没有文献可以展示</h1><h3>该收藏夹没有文献，或者您还未选中任何收藏夹。</h3><h3>您可以在搜索页面查找并收藏文献！</h3>");
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

    QStringList Tags = getTags();

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
        //添加到布局中
        layout->addWidget(textEdit);


        // 自适应高度
        textEdit->document()->adjustSize();
        auto h = textEdit->document()->size().height();
        textEdit->setFixedHeight(h);

        QHBoxLayout *layoutH = new QHBoxLayout;

        //取消收藏按钮
        QPushButton *buttonStar = new QPushButton("取消收藏");
        buttonStar->setStyleSheet(ui->pushButton_search->styleSheet());
        auto paperUrl = papers[i].paperUrl;
        connect(buttonStar, &QPushButton::clicked, [this, paperUrl, buttonStar]()
            {
            disstarPaper(paperUrl, buttonStar);
            on_pushButton_tags_clicked();

            // auto Tags = getTags();
            // if(Tags.contains(this->now_tag) == false)
            // {
            //     this->now_tag = "default";
            // }
            this->get_Docu_of_tag(this->now_tag);

            });

        //下载按钮
        QPushButton *buttonPdf = new QPushButton("下载pdf");
        buttonPdf->setStyleSheet(ui->pushButton_search->styleSheet());
        auto pdfUrl = papers[i].pdfUrl;
        connect(buttonPdf, &QPushButton::clicked, [pdfUrl]() { QDesktopServices::openUrl(pdfUrl); });

        //原文链接按钮
        QPushButton *buttonLink = new QPushButton("打开原文链接");
        buttonLink->setStyleSheet(ui->pushButton_search->styleSheet());
        connect(buttonLink, &QPushButton::clicked, [ paperUrl]() { QDesktopServices::openUrl(paperUrl); });

        //添加空间到布局中
        layout->addLayout(layoutH);


        layoutH->addWidget(buttonStar);
        layoutH->addWidget(new QLabel(" "));
        layoutH->addWidget(buttonPdf);
        layoutH->addWidget(buttonLink);
        //添加占位label
        layout->addWidget(new QLabel("\n\n"));

    }
    scrollWidget->setLayout(layout);
    ui->scrollArea_docu_of_tag->setWidget(scrollWidget);
    //滚动到最底部
    QScrollBar *vScrollBar = ui->scrollArea_docu_of_tag->verticalScrollBar();
    // vScrollBar->setValue(vScrollBar->maximum());
    vScrollBar->setStyleSheet(qScrollBarStyle);
}

void MainWindow2::disstarPaper(QString paperUrl, QPushButton* button)
{
    QString originalText = button->text();
    button->setText("取消收藏中");
    button->setEnabled(0);
    QString searchUrl = UrlofStar;
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
        button->setText(originalText);
        button->setEnabled(0);
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
        button->setText(originalText);
        button->setEnabled(1);
        return;
    }

    QNetworkRequest aiQuestionRequest((QUrl(searchUrl)));
    aiQuestionRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    aiQuestionRequest.setRawHeader("Referer", searchUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("entry_id", paperUrl);
    params.addQueryItem("cancel_button", "cancel_collect");
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    QNetworkReply *starQuestionReply = manager.post(aiQuestionRequest, params.query(QUrl::FullyEncoded).toUtf8());

    QEventLoop loop2;
    QObject::connect(starQuestionReply, &QNetworkReply::finished, &loop2, &QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (starQuestionReply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << starQuestionReply->errorString();
        starQuestionReply->deleteLater();
        button->setText(originalText);
        button->setEnabled(1);
        return;
    }
}


void MainWindow2::on_listWidget_tag_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(!current)
    {
        get_Docu_of_tag("");
        //ui->listWidget_tag->setCurrentRow(0);
        return;
    }
    get_Docu_of_tag(current->text());
}

void MainWindow2::on_pushButton_tagsFliter_clicked()
{
    QString keyword = ui->lineEdit_tagKeyword->text();
    auto originalTags = getTags();
    QStringList Tags;
    for(auto it: originalTags)
    {
        if(it.contains(keyword))
        {
            Tags.push_back(it);
        }
    }
    display_tags(Tags);
}


void MainWindow2::on_lineEdit_tagKeyword_returnPressed()
{
    on_pushButton_tagsFliter_clicked();
}

//获取当前感兴趣
QStringList MainWindow2::get_interested_fields()
{
    QStringList fields;
    QString searchUrl = UrlofPush;
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
        return fields;
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
        return fields;
    }

    QNetworkRequest fieldsRequest((QUrl(searchUrl)));
    fieldsRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    fieldsRequest.setRawHeader("Referer", searchUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    QNetworkReply *fieldsReply = manager.post(fieldsRequest, params.query(QUrl::FullyEncoded).toUtf8());



    QEventLoop loop2;
    QObject::connect(fieldsReply,&QNetworkReply::finished,&loop2,&QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (fieldsReply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << fieldsReply->errorString();
        fieldsReply->deleteLater();
        return fields;
    }

    // 读取响应内容
    QString html = fieldsReply->readAll();
    fieldsReply->deleteLater();

    // 取出有用的部分
    QString start_marker = "***";
    QString end_marker = "###";
    int startIndex = html.indexOf(start_marker);
    int endIndex = html.indexOf(end_marker);

    if(startIndex != -1 && endIndex != -1 && startIndex < endIndex)
    {
        startIndex +=start_marker.size();
        if(html=="未设置兴趣领域")
            return fields;
    }
    else
    {
        qWarning()<<"网页链接失败";
    }

    html=html.mid(startIndex,endIndex-startIndex);
    html=html.remove("\n");
    html = html.remove(" ");

    // 定义正则表达式来匹配由 %%% 和 $$$ 包围的内容
    QRegularExpression re("%%%([^$]+)\\$\\$\\$");
    QRegularExpressionMatchIterator i = re.globalMatch(html);

    // 提取并输出匹配的内容
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString field = match.captured(1);  // captured(1) 获取第一个捕获组的内容
        fields.append(field);
    }

    return fields;
}

void MainWindow2::displayfields(QStringList &fields)
{
    ui->listWidget_interested->clear();

    if(fields.empty())
    {
        ui->listWidget_interested->addItem("请添加感兴趣的领域");
    }
    else
    {
        QStringList translatedFields;
        for(const QString &field : fields)
        {
            translatedFields.append(mapField.key(field));
        }

        ui->listWidget_interested->addItems(translatedFields);
        ui->listWidget_interested->setCurrentRow(0);
    }
}



void MainWindow2::fresh_fields()
{
    QStringList fields=this->get_interested_fields();
    // QStringList fields;
    this->displayfields(fields);
}

void MainWindow2::on_pushButton_add_interested_clicked()
{
    QString searchUrl = UrlofPush;
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

    QNetworkRequest Request((QUrl(searchUrl)));
    Request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    Request.setRawHeader("Referer", searchUrl.toUtf8());

    QString field = ui->comboBox_field_interested->currentText();
    field = mapField[field];
    QUrlQuery params;
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    params.addQueryItem("field_input", field);
    params.addQueryItem("add_field_button", "add_field");
    QNetworkReply *Reply = manager.post(Request, params.query(QUrl::FullyEncoded).toUtf8());



    QEventLoop loop2;
    QObject::connect(Reply,&QNetworkReply::finished,&loop2,&QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (Reply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << Reply->errorString();
        Reply->deleteLater();
        return;
    }

    this->fresh_fields();
}



void MainWindow2::on_pushButton_delete_interested_clicked()
{
    QString searchUrl = UrlofPush;
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

    QNetworkRequest Request((QUrl(searchUrl)));
    Request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    Request.setRawHeader("Referer", searchUrl.toUtf8());

    QString field = ui->listWidget_interested->currentItem()->text();
    field = mapField.value(field);
    QUrlQuery params;
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);
    params.addQueryItem("field_to_delete", field);
    params.addQueryItem("delete_field_button", "delete_field");
    QNetworkReply *Reply = manager.post(Request, params.query(QUrl::FullyEncoded).toUtf8());



    QEventLoop loop2;
    QObject::connect(Reply,&QNetworkReply::finished,&loop2,&QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (Reply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << Reply->errorString();
        Reply->deleteLater();
        return;
    }

    this->fresh_fields();
}

QVector<Paper> MainWindow2::paperPush()
{
    QVector<Paper> papers;
    QString searchUrl = UrlofPush;
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
        csrfToken = csrfToken.right(66);
        csrfToken = csrfToken.left(64);
    } else {
        return papers;
    }

    QNetworkRequest Request((QUrl(searchUrl)));
    Request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    Request.setRawHeader("Referer", searchUrl.toUtf8());

    QUrlQuery params;
    params.addQueryItem("push_paper_button", "push_paper");
    params.addQueryItem("csrfmiddlewaretoken", csrfToken);

    QNetworkReply *Reply = manager.post(Request, params.query(QUrl::FullyEncoded).toUtf8());



    QEventLoop loop2;
    QObject::connect(Reply,&QNetworkReply::finished,&loop2,&QEventLoop::quit);
    loop2.exec();

    // 检查请求状态
    if (Reply->error() != QNetworkReply::NoError) {
        qWarning() << "Error:" << Reply->errorString();
        Reply->deleteLater();
        return papers;
    }

    // 读取响应内容
    QString html = Reply->readAll();
    Reply->deleteLater();

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

void MainWindow2::display_push(QVector<Paper>&papers)
{
    ui->scrollArea_docu_of_push->setWidgetResizable(true);

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

        textEdit->setHtml("<h1>请刷新推送</h1>");
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

    QStringList Tags = getTags();

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
        //添加到布局中
        layout->addWidget(textEdit);


        // 自适应高度
        textEdit->document()->adjustSize();
        auto h = textEdit->document()->size().height();
        textEdit->setFixedHeight(h);

        QHBoxLayout *layoutH = new QHBoxLayout;

        //标签选择框
        layoutH->addWidget(new QLabel(" 选择 / 输入一个标签："));
        QComboBox *tagCombo = new QComboBox();


        //收藏按钮
        QPushButton *buttonStar = new QPushButton("收藏此文章");
        buttonStar->setStyleSheet(ui->pushButton_search->styleSheet());
        auto paperUrl = papers[i].paperUrl;
        connect(buttonStar, &QPushButton::clicked, [this, paperUrl, tagCombo, buttonStar]() { starPaper(paperUrl,tagCombo, buttonStar); });

        //下载按钮
        QPushButton *buttonPdf = new QPushButton("下载pdf");
        buttonPdf->setStyleSheet(ui->pushButton_search->styleSheet());
        auto pdfUrl = papers[i].pdfUrl;
        connect(buttonPdf, &QPushButton::clicked, [pdfUrl]() { QDesktopServices::openUrl(pdfUrl); });

        //原文链接按钮
        QPushButton *buttonLink = new QPushButton("打开原文链接");
        buttonLink->setStyleSheet(ui->pushButton_search->styleSheet());
        connect(buttonLink, &QPushButton::clicked, [ paperUrl]() { QDesktopServices::openUrl(paperUrl); });

        //添加空间到布局中
        layout->addLayout(layoutH);



        tagCombo->setEditable(true);
        tagCombo->setStyleSheet(ui->comboBox_field->styleSheet());
        tagCombo->addItems(Tags);
        layoutH->addWidget(tagCombo);
        layoutH->addWidget(buttonStar);
        layoutH->addWidget(new QLabel(" "));
        layoutH->addWidget(buttonPdf);
        layoutH->addWidget(buttonLink);
        //添加占位label
        layout->addWidget(new QLabel("\n\n"));

    }
    scrollWidget->setLayout(layout);
    ui->scrollArea_docu_of_push->setWidget(scrollWidget);
    //滚动到最底部
    QScrollBar *vScrollBar = ui->scrollArea_docu_of_push->verticalScrollBar();
    // vScrollBar->setValue(vScrollBar->maximum());
    vScrollBar->setStyleSheet(qScrollBarStyle);
}

void MainWindow2::on_pushButton_refresh_push_clicked()
{
    QVector<Paper> papers = this->paperPush();
}

