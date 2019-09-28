#ifndef CONNECTIONDLG_H
#define CONNECTIONDLG_H

#include <QDialog>
#include"connection.h"
namespace Ui {
class ConnectionDlg;
}

class ConnectionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDlg(QWidget *parent = nullptr);
    ~ConnectionDlg();


private slots:


    void on_SqlServerConnection_Btn_clicked();

private:
    Ui::ConnectionDlg *connection_ui;

};

extern QString HostName;
extern QString UserName;
extern QString Passwd;
extern QString ServerIP;
extern QString LibaryName1;
extern QString LibaryName;


#endif // CONNECTIONDLG_H
