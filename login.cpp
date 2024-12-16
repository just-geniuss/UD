#include "login.h"
#include "ui_login.h"
#include <QSqlDatabase>


login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);



    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    mes = new QMessageBox();

}

login::~login()
{


    delete ui;
}

void login::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions("Driver={ODBC Driver 18 for SQL Server};");
    //db.setDatabaseName("DRIVER={SQL Server};SERVER="+ui->lineEdit->text()+";DATABASE="+ui->lineEdit_2->text()+";");
    //db.setDatabaseName("DRIVER={ODBC Driver 18 for SQL Server};SERVER="
    //+ ui->lineEdit->text() + ";DATABASE=" + ui->lineEdit_2->text() + ";TrustServerCertificate=Yes;");




    db.setHostName("127.0.0.1");
    db.setPort(1433);
    db.setUserName("sa");
    db.setPassword("DB_Password");
    db.setDatabaseName("master");


    qDebug() << db.isDriverAvailable("QODBC");

    //db.setUserName(ui->label_3->text());
    //db.setPassword(ui->lineEdit_4->text());

    if(db.open()){
        mes->setText("Success!");
    }
    else{
        mes->setText("Error");
    }

    mes->show();
}
