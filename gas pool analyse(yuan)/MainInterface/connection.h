#ifndef CONNECTION_H
#define CONNECTION_H
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlDatabase>
#include"connectiondlg.h"
#include<QSqlError>
#include"ui_connectiondlg.h"
#include<QDebug>


static void createConnection(){

    extern QString HostName;
    extern QString UserName;
    extern QString Passwd;
   // extern QString ServerIP;
    extern QString LibaryName1;


   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                                "SERVER=%1;"
                                "DATABASE=%2;"
                                "UID=%3;"
                                "PWD=%4;").arg(HostName)
                        .arg(LibaryName1)
                        .arg(UserName)
                        .arg(Passwd));
     //"PEData_V6.4_MultiLanguagee_Metric_0805"
// "PC*******\\SQLEXPRESS"也可以换成"PC*******，1433"
     if (!db.open())
     {
         QMessageBox::warning(0, qApp->tr("Cannot open database"), db.lastError().databaseText(), QMessageBox::Cancel);
     }
     else
     {
         qDebug()<<"Connect to Database Success!";
     }


}

/*

    QString strDriver = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2").arg(ServerIP).arg(LibaryName1);
        QSqlDatabase m_db=QSqlDatabase::addDatabase("QODBC");//初始化时候要传类型 不要可能有错误
        m_db.setDatabaseName(strDriver);
        m_db.setHostName(ServerIP);
        m_db.setUserName(UserName);//用户名密码 必须单独设置一次
        m_db.setPassword(Passwd);

        if(!m_db.open())//打开数据库失败会出现相应的错误信息和提示
            {
                qDebug()<<m_db.lastError().text();
                QMessageBox::critical(0,QObject::tr("Cannot open database1"),m_db.lastError().text(),QMessageBox::Cancel);
                return ;
      }
}
*/
#endif // CONNECTION_H
