#include "maininterface.h"
#include <QApplication>
#include"connectiondlg.cpp"
#include"connection.h"
#include"logindlg.h"
#include"usermanagement.h"
#include"mymdi.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainInterface w;
    UserManagement usermanagement;
    //连接数据库
//if(!createConnection()) return 1;
    /*
    //登陆对话框
    loginDlg login;
    if(login.exec()==QDialog::Accepted)
        {
        w.show();
        usermanagement.show();

        return a.exec();
    }
    else return 0;
*/

    //连接对话框
    ConnectionDlg login;
    if(login.exec()==QDialog::Accepted)
        {
        MainInterface f;
        f.show();
        return a.exec();

    }
    else return 0;



//    MainInterface w;
 //   w.show();
    return a.exec();
//w.show();
}

