#ifndef login_H
#define login_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox>
#include <QSettings>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QShortcut>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    QMessageBox* mes;

private slots:
    void on_pushButton_clicked();

signals:
    void refreshComboBox();

private:
    void saveSettings();
    Ui::login *ui;
    QSqlDatabase db;
};

#endif // login_H
