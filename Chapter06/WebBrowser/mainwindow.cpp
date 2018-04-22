#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webview = new QWebEngineView(ui->webviewFrame);

    connect(webview, &QWebEngineView::loadProgress, this, &MainWindow::webviewLoading);
    connect(webview, &QWebEngineView::loadFinished, this, &MainWindow::webviewLoaded);

    loadPage();

    // Enable cookie
    QWebEngineProfile::defaultProfile()->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);

    // No cache
    QWebEngineProfile::defaultProfile()->setHttpCacheType(QWebEngineProfile::NoCache);

    // Delete all browsing history
    QWebEngineProfile::defaultProfile()->clearAllVisitedLinks();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    webview->resize(ui->webviewFrame->size());
}

void MainWindow::loadPage()
{
    QString url = ui->addressInput->text();
    if (!url.startsWith("http://") && !url.startsWith("https://"))
    {
	url = "http://" + url;
    }
    ui->addressInput->setText(url);
    webview->load(QUrl(url));
}

void MainWindow::on_backButton_clicked()
{
    webview->back();
}

void MainWindow::on_forwardButton_clicked()
{
    webview->forward();
}

void MainWindow::on_refreshButton_clicked()
{
    webview->reload();
}

void MainWindow::on_goButton_clicked()
{
    loadPage();
}

void MainWindow::on_addressInput_returnPressed()
{
    loadPage();
}

void MainWindow::webviewLoading(int progress)
{
    ui->progressBar->setValue(progress);
}

void MainWindow::webviewLoaded()
{
    ui->addressInput->setText(webview->url().toString());
}
