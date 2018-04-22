#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebChannel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Q_INVOKABLE void doSomething();

protected:
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QWebEngineView* webview;
};

#endif // MAINWINDOW_H
