#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>

namespace Ui {
class MainWindow2;
}

struct Paper;

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
    void displayHistory();
    void displaySearchResult(const QVector<Paper>& papers);

private slots:

    void on_pushButton_refreshAiHistory_clicked();

    void on_pushButton_question_clicked();

    void on_textEdit_question_textChanged();

    void showDotAI();

    void showDotSearch();

    void on_pushButton_AI__chat_page_clicked();

    void on_pushButton_Document_manage_page_clicked();

    void on_pushButton_Document_query_page_clicked();

    void on_pushButton_Mine_page_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_minimize_clicked();

    void on_pushButton_close_clicked();

    void on_stackedWidget_currentChanged();

    void on_pushButton_translate_page_clicked();

    void on_textEdit_translate_textChanged();

    void on_pushButton_translate_clicked();

    void on_pushButton_tags_clicked();

    void starPaper(QString paperUrl, QComboBox* tagBox, QPushButton* button);

    void on_lineEdit_returnPressed();

    void on_pushButton_last_pgae_clicked();
    void on_pushButton_next_pgae_clicked();
    void on_lineEdit_display_page_returnPressed();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    Ui::MainWindow2 *ui;
    bool m_dragging = false;
    QPoint m_dragPosition;
    QStringList history;
    QStringList getAiHistory();
    void question_to_AI(QString question);
    QStringList getTags();
    void display_tags(QStringList &TagList);
    void get_Docu_of_tag(QString tag);
    void display_Docu_of_tag(QVector<Paper> &papers);
    QVector<Paper> paperSearch(const QString &keyword, const QString &field,
                               const QString &sortType, const QString &sortOrder);
    QMap<QString, QString> mapField;
    void initFieldMap()
    {
        mapField.insert("不限领域", "");
        mapField.insert("天体物理", "astro-ph");
        mapField.insert("宇宙学与非规则天体物理学", "astro-ph.CO");
        mapField.insert("地球与行星天体物理学", "astro-ph.EP");
        mapField.insert("星系天体物理学", "astro-ph.GA");
        mapField.insert("高能天体物理现象", "astro-ph.HE");
        mapField.insert("天体物理学的仪器和方法", "astro-ph.IM");
        mapField.insert("太阳与恒星天体物理学", "astro-ph.SR");
        mapField.insert("无序系统与神经网络", "cond-mat.dis-nn");
        mapField.insert("中尺度和纳米尺度物理学", "cond-mat.mes-hall");
        mapField.insert("材料科学", "cond-mat.mtrl-sci");
        mapField.insert("其他凝聚态", "cond-mat.other");
        mapField.insert("量子气体", "cond-mat.quant-gas");
        mapField.insert("软凝聚物", "cond-mat.soft");
        mapField.insert("统计力学", "cond-mat.stat-mech");
        mapField.insert("强关联电子", "cond-mat.str-el");
        mapField.insert("超导现象", "cond-mat.supr-con");
        mapField.insert("人工智能", "cs.AI");
        mapField.insert("硬件架构", "cs.AR");
        mapField.insert("计算复杂性", "cs.CC");
        mapField.insert("计算工程，金融和科学", "cs.CE");
        mapField.insert("计算几何", "cs.CG");
        mapField.insert("计算与语言", "cs.CL");
        mapField.insert("密码学与安全", "cs.CR");
        mapField.insert("计算机视觉与模式识别", "cs.CV");
        mapField.insert("电脑与社会", "cs.CY");
        mapField.insert("数据库", "cs.DB");
        mapField.insert("分布式、并行和集群计算", "cs.DC");
        mapField.insert("数字仓库", "cs.DL");
        mapField.insert("离散数学", "cs.DM");
        mapField.insert("数据结构和算法", "cs.DS");
        mapField.insert("新兴科技", "cs.ET");
        mapField.insert("形式语言与自动机理论", "cs.FL");
        mapField.insert("一般文学", "cs.GL");
        mapField.insert("图形", "cs.GR");
        mapField.insert("计算机科学与博弈论", "cs.GT");
        mapField.insert("人机交互", "cs.HC");
        mapField.insert("信息检索", "cs.IR");
        mapField.insert("信息理论", "math.IT");
        mapField.insert("学习", "cs.LG");
        mapField.insert("计算机科学中的逻辑", "cs.LO");
        mapField.insert("多代理系统", "cs.MA");
        mapField.insert("多媒体", "cs.MM");
        mapField.insert("数学软件", "cs.MS");
        mapField.insert("数值分析", "math.NA");
        mapField.insert("神经和进化计算", "cs.NE");
        mapField.insert("网络与互联网架构", "cs.NI");
        mapField.insert("其他计算机科学", "cs.OH");
        mapField.insert("操作系统", "cs.OS");
        mapField.insert("性能", "cs.PF");
        mapField.insert("编程语言", "cs.PL");
        mapField.insert("机器人技术", "cs.RO");
        mapField.insert("符号计算", "cs.SC");
        mapField.insert("声音", "cs.SD");
        mapField.insert("软件工程", "cs.SE");
        mapField.insert("社会和信息网络", "cs.SI");
        mapField.insert("系统及控制", "cs.SY");
        mapField.insert("计量经济学", "econ.EM");
        mapField.insert("音频及语音处理", "eess.AS");
        mapField.insert("图像和视频处理", "eess.IV");
        mapField.insert("信号处理", "eess.SP");
        mapField.insert("广义相对论和量子宇宙学", "gr-qc");
        mapField.insert("高能物理实验", "hep-ex");
        mapField.insert("高能物理-晶格", "hep-lat");
        mapField.insert("高能物理-现象学", "hep-ph");
        mapField.insert("高能物理理论", "hep-th");
        mapField.insert("交换代数", "math.AC");
        mapField.insert("代数几何", "math.AG");
        mapField.insert("偏微分方程分析", "math.AP");
        mapField.insert("代数拓扑", "math.AT");
        mapField.insert("传统分析和微分方程", "math.CA");
        mapField.insert("组合数学", "math.CO");
        mapField.insert("范畴理论", "math.CT");
        mapField.insert("复杂变量", "math.CV");
        mapField.insert("微分几何", "math.DG");
        mapField.insert("动力系统", "math.DS");
        mapField.insert("功能分析", "math.FA");
        mapField.insert("普通数学", "math.GM");
        mapField.insert("点集拓扑学", "math.GN");
        mapField.insert("群论", "math.GR");
        mapField.insert("几何拓扑学", "math.GT");
        mapField.insert("历史和概述", "math.HO");
        mapField.insert("K 理论与同调", "math.KT");
        mapField.insert("逻辑", "math.LO");
        mapField.insert("度量几何学", "math.MG");
        mapField.insert("数学物理", "math-ph");
        mapField.insert("数论", "math.NT");
        mapField.insert("算子代数", "math.OA");
        mapField.insert("优化和控制", "math.OC");
        mapField.insert("概率", "math.PR");
        mapField.insert("子代数", "math.QA");
        mapField.insert("环与代数", "math.RA");
        mapField.insert("表示论", "math.RT");
        mapField.insert("辛几何", "math.SG");
        mapField.insert("光谱理论", "math.SP");
        mapField.insert("统计学理论", "stat.TH");
        mapField.insert("适应与自组织系统", "nlin.AO");
        mapField.insert("混沌动力学", "nlin.CD");
        mapField.insert("元胞自动机与格子气体", "nlin.CG");
        mapField.insert("模式形成与孤子", "nlin.PS");
        mapField.insert("严格可解可积系统", "nlin.SI");
        mapField.insert("核试验", "nucl-ex");
        mapField.insert("核理论", "nucl-th");
        mapField.insert("加速器物理学", "physics.acc-ph");
        mapField.insert("大气和海洋物理学", "physics.ao-ph");
        mapField.insert("应用物理学", "physics.app-ph");
        mapField.insert("原子和分子团簇", "physics.atm-clus");
        mapField.insert("原子物理学", "physics.atom-ph");
        mapField.insert("生物物理学", "physics.bio-ph");
        mapField.insert("化学物理", "physics.chem-ph");
        mapField.insert("经典物理学", "physics.class-ph");
        mapField.insert("计算物理学", "physics.comp-ph");
        mapField.insert("数据分析、统计和概率", "physics.data-an");
        mapField.insert("物理教育", "physics.ed-ph");
        mapField.insert("流体动力学", "physics.flu-dyn");
        mapField.insert("普通物理", "physics.gen-ph");
        mapField.insert("地球物理学", "physics.geo-ph");
        mapField.insert("物理学的历史与哲学", "physics.hist-ph");
        mapField.insert("仪器和探测器", "physics.ins-det");
        mapField.insert("医学物理学", "physics.med-ph");
        mapField.insert("光学", "physics.optics");
        mapField.insert("等离子体物理", "physics.plasm-ph");
        mapField.insert("大众物理", "physics.pop-ph");
        mapField.insert("物理学与社会", "physics.soc-ph");
        mapField.insert("空间物理学", "physics.space-ph");
        mapField.insert("生物分子", "q-bio.BM");
        mapField.insert("细胞行为", "q-bio.CB");
        mapField.insert("基因组学", "q-bio.GN");
        mapField.insert("分子网络", "q-bio.MN");
        mapField.insert("神经元与认知", "q-bio.NC");
        mapField.insert("其他定量生物学", "q-bio.OT");
        mapField.insert("种群与进化", "q-bio.PE");
        mapField.insert("定量方法", "q-bio.QM");
        mapField.insert("亚细胞突起", "q-bio.SC");
        mapField.insert("组织和器官", "q-bio.TO");
        mapField.insert("金融工程", "q-fin.CP");
        mapField.insert("经济学", "q-fin.EC");
        mapField.insert("财务概述", "q-fin.GN");
        mapField.insert("数学金融", "q-fin.MF");
        mapField.insert("投资组合管理", "q-fin.PM");
        mapField.insert("证券定价", "q-fin.PR");
        mapField.insert("风险管理", "q-fin.RM");
        mapField.insert("金融统计", "q-fin.ST");
        mapField.insert("交易与市场微观结构", "q-fin.TR");
        mapField.insert("量子物理学", "quant-ph");
        mapField.insert("应用", "stat.AP");
        mapField.insert("计算", "stat.CO");
        mapField.insert("方法论", "stat.ME");
        mapField.insert("机器学习", "stat.ML");
        mapField.insert("其他统计学", "stat.OT");
    }
    QVector<Paper> Paper_searchResult;//论文查询结果
    int Page_searchResult_n = 0;
    int display_serchResult_n = 0;

};

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


#endif // MAINWINDOW2_H
