#include "connectiondlg.h"
#include "ui_connectiondlg.h"
#include<QSqlDatabase>
//#include<qDebug>
#include<QSqlError>
#include<QMessageBox>

QString HostName;
QString UserName;
QString Passwd;
QString ServerIP;
QString LibaryName1;
QString LibaryName;

ConnectionDlg::ConnectionDlg(QWidget *parent) :
    QDialog(parent),
   connection_ui(new Ui::ConnectionDlg)
{
    connection_ui->setupUi(this);


}


ConnectionDlg::~ConnectionDlg()
{
    delete connection_ui;
}



//连接数据库
void ConnectionDlg::on_SqlServerConnection_Btn_clicked()
{
    /*
    connection_ui->SqlServerConnection_Btn->setEnabled(false);
    HostName=connection_ui->ServerIp_LineEdit->text();
    UserName=connection_ui->User_LineEdit->text();
    Passwd=connection_ui->Passwd_LineEdit->text();
    ServerIP=connection_ui->ServerIp_LineEdit->text();
    LibaryName1=connection_ui->Libary_name_LineEdit->text();
    qDebug()<<LibaryName;
    qDebug()<<HostName;
    qDebug()<<UserName;
    qDebug()<<Passwd;
    LibaryName=connection_ui->Libary_name_LineEdit->text();
*/
   //HostName="localhost";
    //UserName="sa";
   //Passwd="a112233.";
    //ServerIP="localhost";
   // LibaryName1="PEData_V6.4_MultiLanguagee_Metric_0805";
   // LibaryName="PEData_V6.4_MultiLanguagee_Metric_0805";

        QSqlDatabase m_db=QSqlDatabase::addDatabase("QSQLITE");//初始化时候要传类型 不要可能有错误
        m_db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                   "SERVER=%1;"
                                   "DATABASE=%2;"
                                   "UID=%3;"
                                   "PWD=%4;").arg(HostName)
                           .arg(LibaryName1)
                           .arg(UserName)
                           .arg(Passwd));

        if(!m_db.open())//打开数据库失败会出现相应的错误信息和提示
            {
            connection_ui->SqlServerConnection_Btn->setEnabled(true);
                qDebug()<<m_db.lastError().text();
                QMessageBox::critical(0,QObject::tr("Cannot open database1"),m_db.lastError().text(),QMessageBox::Ok);

                connection_ui->Lib_Con_Status_Label->setText(tr("连接状态:连接失败!"));
                return;

        }
        connection_ui->SqlServerConnection_Btn->setEnabled(true);
        accept();
        connection_ui->Lib_Con_Status_Label->setText(tr("连接状态:连接成功!"));

}
