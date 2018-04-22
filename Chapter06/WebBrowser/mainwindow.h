#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineProfile>
#include <QWebEnginePage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadPage();

protected:
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_backButton_clicked();
    void on_forwardButton_clicked();
    void on_refreshButton_clicked();
    void on_goButton_clicked();
    void on_addressInput_returnPressed();

    void webviewLoading(int progress);
    void webviewLoaded();

private:
    Ui::MainWindow *ui;
    QWebEngineView* webview;
};

#endif // MAINWINDOW_H
