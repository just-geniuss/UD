#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    delete ui;
}

void MainWindow::on_action_triggered()
{
    logwin = new login();
    logwin->show();
}

