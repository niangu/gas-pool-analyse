#include "logindlg.h"
#include "ui_logindlg.h"
#include<QMessageBox>
loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);
    ui->Passwd_LineEdit->setEchoMode(QLineEdit::Password);
}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_Login_Btn_clicked()
{
    //判断用户名和密码是否正确,trimmed移除字符串开头和结尾的空白字符
if(ui->Usr_LineEdit->text().trimmed()==tr("qt")&&ui->Passwd_LineEdit->text()==tr("123456"))
    accept();
else{
    //如果不正确，弹出警告对话框
    QMessageBox::warning(this, tr("Warning"), tr("user name or password error!"),
                         QMessageBox::Yes);
    ui->Usr_LineEdit->clear();//清空用户名输入框
    ui->Passwd_LineEdit->clear();//清空密码输入框
    ui->Usr_LineEdit->setFocus();//将光标转到用户名输入框
}
}
