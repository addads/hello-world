#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "networkrequest.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_w_makeRequest_clicked();
    void dataToDisplay(QByteArray data);

private:
    Ui::MainWindow *ui;
    networkRequest netReq;

};

#endif // MAINWINDOW_H
