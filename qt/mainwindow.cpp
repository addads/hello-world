#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&netReq, SIGNAL(dataOutOfTheOven(QByteArray)), this, SLOT(dataToDisplay(QByteArray)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_w_makeRequest_clicked()
{
    if(ui->w_insertURL->text() != "")
    {
        qDebug() << "URL: " << ui->w_insertURL->text();
        netReq.makeRequest(ui->w_insertURL->text());
    }
}

void MainWindow::dataToDisplay(QByteArray data)
{
    QString text(data);
    qDebug() << text;
    ui->w_displayText->setText(text);
}
