#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <QDebug>
#include <QMessageBox>

#include <QtCharts>
#include <QChartView>

#include <QBarSet>
#include <QBarSeries>

#include <QPieSeries>
#include <QPieSlice>

#include <QLineSeries>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void resizeEvent(QResizeEvent* event);

private slots:
    void on_loginButton_clicked();
    void on_stackedWidget_currentChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

    QChartView *chartViewBar;
    QChartView *chartViewPie;
    QChartView *chartViewLine;
};

#endif // MAINWINDOW_H
