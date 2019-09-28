#include "maininterface.h"
#include "ui_maininterface.h"
#include"connectiondlg.h"
#include<QSqlTableModel>
#include<connection.h>
#include<QSqlQuery>
#include<QStandardItem>
#include<QListWidgetItem>
#include<QTreeWidgetItem>
#include<QTimer>
#include<ui_mymdi.h>
#include"mymdi.h"
#include<QFileDialog>
#include<QStandardPaths>
//#include<ActiveQt/QAxObject>
#include<QDesktopServices>
//QString LibaryName;
MainInterface::MainInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterface)
{
    ui->setupUi(this);
    createConnection();
    extern QString LibaryName;
    //QSqlQuery ColumnNamequery;
    QSqlQuery TableNameQuery;
    model = new QSqlQueryModel(this);//模块一
    Tablemodel = new QSqlTableModel(this);//模块一
    model1 = new QSqlQueryModel(this);//模块1:2TreeView
    capacityquerymodel = new QSqlQueryModel(this);//产能


    //查询所有表名
    TableNameQuery.exec("select name from sysobjects where xtype='u' order by name");
    while(TableNameQuery.next())
    {
        //qDebug()<<TableNameQuery.value(0).toStringList();
        QStringList TableNameList = TableNameQuery.value(0).toStringList();
        ui->ComboBox_TableName->addItems(TableNameList);
        ui->ComboBox_TableName_2->addItems(TableNameList);
        ui->comboBox_capacity->addItems(TableNameList);
    }

    QString  cur_capacity_table_name = ui->comboBox_capacity->currentText();
     capacityquerymodel->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(cur_capacity_table_name));
     ui->tableView_capacity->setModel(capacityquerymodel);

    //更具筛选框设置功能
    QString curtablename = ui->ComboBox_TableName->currentText();
    switch (ui->ComboBox_Chioceopeater->currentIndex()) {
    case 0:

        ui->ListWidget_ColumnName_2->setEnabled(true);
        ui->ListWidget_ColumnSeleced->setEnabled(true);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        //ui->lineEdit->setEnabled(false);

         model->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(curtablename));
        ui->tableView->setModel(model);
        break;
    case 1:
        ui->ListWidget_ColumnName_2->setEnabled(false);
        ui->ListWidget_ColumnSeleced->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->lineEdit->setEnabled(true);
        Tablemodel->setTable(curtablename);
        Tablemodel->select();
        ui->tableView->setModel(Tablemodel);
        //设置编辑策略
        // Tablemodel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    default:
        break;
    }

ui->tableView_2->setModel(model1);

//数据查询：树控件
//ui->treeWidget->setHeaderLabels(QStringList()<<"名称"<<"字段");
treemodel = new QStandardItemModel(ui->treeView);
ui->treeView->setModel(treemodel);
treemodel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("名称"));     //设置列头
//状态标签
//int columnscount = model->columnCount();
//int rowcount = model->rowCount();
//ui->label_stats_2->setText(tr("当前表总列数:%2").arg(columnscount));
//int columnscount2 = model1->columnCount();
//ui->label_stats->setText(tr("当前表的总列数:%2").arg(columnscount2));

}

MainInterface::~MainInterface()
{
    delete ui;
}
//重注册
void MainInterface::on_action_connection_triggered()
{
        //连接对话框

        ConnectionDlg login;
        if(login.exec()==QDialog::Accepted)
            {
            createConnection();
            extern QString LibaryName;
            //QSqlQuery ColumnNamequery;
            QSqlQuery TableNameQuery;
            model = new QSqlQueryModel(this);//模块一
            Tablemodel = new QSqlTableModel(this);//模块一
            model1 = new QSqlQueryModel(this);//模块1:2TreeView

            //查询所有表名
            TableNameQuery.exec("select name from sysobjects where xtype='u' order by name");
            while(TableNameQuery.next())
            {
                //qDebug()<<TableNameQuery.value(0).toStringList();
                QStringList TableNameList = TableNameQuery.value(0).toStringList();
                ui->ComboBox_TableName->addItems(TableNameList);
                ui->ComboBox_TableName_2->addItems(TableNameList);

            }

            //更具筛选框设置功能
            QString curtablename = ui->ComboBox_TableName->currentText();
            switch (ui->ComboBox_Chioceopeater->currentIndex()) {
            case 0:

                ui->ListWidget_ColumnName_2->setEnabled(true);
                ui->ListWidget_ColumnSeleced->setEnabled(true);
                ui->pushButton->setEnabled(false);
                ui->pushButton_2->setEnabled(false);
                ui->pushButton_3->setEnabled(false);
                ui->pushButton_4->setEnabled(false);
                ui->pushButton_5->setEnabled(false);
                ui->pushButton_6->setEnabled(false);
                ui->pushButton_7->setEnabled(false);
                ui->pushButton_8->setEnabled(false);
                ui->pushButton_9->setEnabled(false);
                ui->lineEdit->setEnabled(false);

                 model->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(curtablename));
                ui->tableView->setModel(model);
                break;
            case 1:
                ui->ListWidget_ColumnName_2->setEnabled(false);
                ui->ListWidget_ColumnSeleced->setEnabled(false);
                ui->pushButton->setEnabled(true);
                ui->pushButton_2->setEnabled(true);
                ui->pushButton_3->setEnabled(true);
                ui->pushButton_4->setEnabled(true);
                ui->pushButton_5->setEnabled(true);
                ui->pushButton_6->setEnabled(true);
                ui->pushButton_7->setEnabled(true);
                ui->pushButton_8->setEnabled(true);
                ui->pushButton_9->setEnabled(true);
                ui->lineEdit->setEnabled(true);
                Tablemodel->setTable(curtablename);
                Tablemodel->select();
                ui->tableView->setModel(Tablemodel);
                //设置编辑策略
                // Tablemodel->setEditStrategy(QSqlTableModel::OnManualSubmit);

            default:
                break;
            }

        ui->tableView_2->setModel(model1);

        //数据查询：树控件
        //ui->treeWidget->setHeaderLabels(QStringList()<<"名称"<<"字段");
        treemodel = new QStandardItemModel(ui->treeView);
        ui->treeView->setModel(treemodel);
        treemodel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("名称"));     //设置列头
        //状态标签
        int columnscount = model->columnCount();
        //int rowcount = model->rowCount();
        //ui->label_stats_2->setText(tr("当前表总列数:%2").arg(columnscount));
        //int columnscount2 = model1->columnCount();
        //ui->label_stats->setText(tr("当前表的总列数:%2").arg(columnscount2));

            return;
        }
        else return;

    }
//导入Excel表
void MainInterface::on_action_open_triggered()
{
/*
    //第一个参数是页面上的表格，第二个是导出文件的表头数据
    // QTableWidget *table,QString title
     QTableView* table=ui->tableView;
     QString title="Sheet";
         QString fileName = QFileDialog::getSaveFileName(table, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xls *.xlsx)");
         if (fileName!="")
         {
             QAxObject *excel = new QAxObject;
             if (excel->setControl("Excel.Application")) //连接Excel控件
             {
                 excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
                 excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
                 QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
                 workbooks->dynamicCall("Add");//新建一个工作簿
                 QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
                 QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

                 int i,j;
                 //QTablewidget 获取数据的列数
                 //int colcount=table->columnCount();
                  //QTablewidget 获取数据的行数
                 //int rowscount=table->rowCount();

                 //QTableView 获取列数
            int colcount=table->model()->columnCount();
                 //QTableView 获取行数
           int rowcount=table->model()->rowCount();
qDebug()<<colcount<<":"<<rowcount;
                 QAxObject *cell,*col;
                 //标题行
                 cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
                 cell->dynamicCall("SetValue(const QString&)", title);
                 cell->querySubObject("Font")->setProperty("Size", 18);
                 //调整行高
                 worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
                 //合并标题行
                 QString cellTitle;
                 cellTitle.append("A1:");
                 cellTitle.append(QChar(colcount - 1 + 'A'));
                 cellTitle.append(QString::number(1));
                 QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
                 range->setProperty("WrapText", true);
                 range->setProperty("MergeCells", true);
                 range->setProperty("HorizontalAlignment", -4108);//xlCenter
                 range->setProperty("VerticalAlignment", -4108);//xlCenter
                 //列标题
                 for(i=0;i<colcount;i++)
                 {
                     QString columnName;
                     columnName.append(QChar(i  + 'A'));
                     columnName.append(":");
                     columnName.append(QChar(i + 'A'));
                     col = worksheet->querySubObject("Columns(const QString&)", columnName);
                     col->setProperty("ColumnWidth", table->columnWidth(i)/6);
                     cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                     //QTableWidget 获取表格头部文字信息
                     //columnName=table->horizontalHeaderItem(i)->text();
                     //QTableView 获取表格头部文字信息
                      columnName=ui->tableView->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                     cell->dynamicCall("SetValue(const QString&)", columnName);
                     cell->querySubObject("Font")->setProperty("Bold", true);
                     cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                     cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                     cell->setProperty("VerticalAlignment", -4108);//xlCenter
                 }

                //数据区

                //QTableWidget 获取表格数据部分
                 /*
                 for(i=0;i<rowcount;i++){
                     for (j=0;j<colcount;j++)
                     {
                         worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", table->item(i,j)?table->item(i,j)->text():"");
                     }
                 }



                //QTableView 获取表格数据部分
                 for(i=0;i<rowcount;i++) //行数
                     {
                        for (j=0;j<colcount;j++)   //列数
                        {
                            QModelIndex index = ui->tableView->model()->index(i, j);
                            QString strdata=ui->tableView->model()->data(index).toString();
                            if(strdata.isEmpty())
                            {
                              worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", "");
                            }
                            worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
                         }
                     }


                 //画框线
                 QString lrange;
                 lrange.append("A2:");
                 lrange.append(colcount - 1 + 'A');
                 lrange.append(QString::number(table->model()->rowCount() + 2));
                 range = worksheet->querySubObject("Range(const QString&)", lrange);
                 range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
                 range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
                 //调整数据区行高
                 QString rowsName;
                 rowsName.append("2:");
                 rowsName.append(QString::number(table->model()->rowCount() + 2));
                 range = worksheet->querySubObject("Range(const QString&)", rowsName);
                 range->setProperty("RowHeight", 20);
                 workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
                 workbook->dynamicCall("Close()");//关闭工作簿
                 excel->dynamicCall("Quit()");//关闭excel
                 delete excel;
                 excel=NULL;
                 if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
                 {
                     QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
                 }
             }
             else
             {
                 QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
             }
}
                 */

    //获取创建的csv文件名
       QString fileName = QFileDialog::getSaveFileName(table, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.csv)");
       if (fileName.isEmpty())
       return;
       //打开.csv文件
       QFile file(fileName);
       if(!file.open(QIODevice::WriteOnly | QIODevice::Text))

       {
           QMessageBox::critical(this,"Error",file.errorString(),QMessageBox::Ok);
           return;
       }
       QTextStream out(&file);
       //获取表格内容
       table = ui->tableView;

       int colcount=table->model()->columnCount();
       //获取列名
       for(int i=0;i<colcount;i++)
       {
         QString columnName=ui->tableView->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
       out<<columnName<<",";
       }
       out<<"\n";
            //QTableView 获取行数
      int rowcount=table->model()->rowCount();
       for(int i=0;i<rowcount;i++) //行数
           {
              for (int j=0;j<colcount;j++)   //列数
              {
                  QModelIndex index = ui->tableView->model()->index(i, j);
                  QString strdata=ui->tableView->model()->data(index).toString();
                  //worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
               out<<strdata<<",";// 写入文件
              }
              out<<"\n";
           }
       QMessageBox::information(this, tr("导出数据成功"), tr("信息已保存在"), tr("确定"));
       file.close();

}
//显示模块操作窗口
void MainInterface::on_action_triggered()
{
    //设置遮罩窗口
    QWidget *ShadeWindow= new QWidget(this);
    QString str("QWidget{background-color:rgba(0,0,0,0.6);}");
    ShadeWindow->setStyleSheet(str);
    ShadeWindow->setGeometry(0, 0, 1, 1);
    ShadeWindow->setGeometry(0, 0, this->width(), this->height());
    ui->dockWidget->show();
    if(ui->dockWidget->isFloating()){
        //QTimer::singleShot(1000,ShadeWindow,ShadeWindow->show);
        //QTimer::singleShot(1000,ShadeWindow,ShadeWindow->hide);
        //QTimer::singleShot(500,ShadeWindow,ShadeWindow->show);
        //QTimer::singleShot(1000,ShadeWindow,ShadeWindow->hide);
    }
}
//显示窗口
void MainInterface::on_action_2_triggered()
{
mymdi=new MyMdi;
mymdi->show();
}
//添加筛选到集成窗口
void MainInterface::on_pushButton_13_clicked()
{
     table = mymdi->addtablewindow();
     QString curtablename = ui->ComboBox_TableName->currentText();
     switch (ui->ComboBox_Chioceopeater->currentIndex()) {
     case 0:
          model->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(curtablename));
         table->setModel(model);
         break;
     case 1:
         Tablemodel->setTable(curtablename);
         Tablemodel->select();
         table->setModel(Tablemodel);
         //设置编辑策略
         // Tablemodel->setEditStrategy(QSqlTableModel::OnManualSubmit);

     default:
         break;
     }
}
//添加树控件到集成窗口
void MainInterface::on_pushButton_14_clicked()
{
    tree = mymdi->addtreewindow();
    tree->setModel(treemodel);
}

//ToolBox变换模块界面初始化
void MainInterface::on_toolBox_currentChanged(int index)
{
    switch (index) {
    case 0:
    {
        int curindex = ui->comboBox->currentIndex();
        ui->stackedWidget->setCurrentIndex(curindex);
        break;
    }
    case 1:
        ui->stackedWidget->setCurrentIndex(2);
        break;

    }
}
//第一模块模块选择
void MainInterface::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_query->setCurrentIndex(0);
        break;
    case 1:
        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_query->setCurrentIndex(1);
    }
}
//筛选功能选择
void MainInterface::on_ComboBox_Chioceopeater_currentIndexChanged(int index)
{
    QString curtablename = ui->ComboBox_TableName->currentText();
     extern QString LibaryName;
    switch (index) {
    case 0:
        ui->ListWidget_ColumnName_2->setEnabled(true);
        ui->ListWidget_ColumnSeleced->setEnabled(true);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->lineEdit->setEnabled(false);
         model->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(curtablename));
        ui->tableView->setModel(model);

        break;
    case 1:
        ui->ListWidget_ColumnName_2->setEnabled(false);
        ui->ListWidget_ColumnSeleced->setEnabled(false);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->lineEdit->setEnabled(true);
        Tablemodel->setTable(curtablename);
        Tablemodel->select();
        ui->tableView->setModel(Tablemodel);
        //设置编辑策略
        // Tablemodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        break;
    default:
        break;
    }
    if(table!=NULL)
    {
        switch (ui->ComboBox_Chioceopeater->currentIndex()) {
        case 0:
             model->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(curtablename));
            table->setModel(model);
            break;
        case 1:
            Tablemodel->setTable(curtablename);
            Tablemodel->select();
            table->setModel(Tablemodel);
            //设置编辑策略
            // Tablemodel->setEditStrategy(QSqlTableModel::OnManualSubmit);

        default:
            break;
        }
    }
}

//提交修改
void MainInterface::on_pushButton_clicked()
{
  //开始事务操作
    Tablemodel->database().transaction();
    if(Tablemodel->submitAll())
    {
        if(Tablemodel->database().commit())//提交
            QMessageBox::information(this, tr("tableModel"),tr("数据修改成功!"));

    }else{
        Tablemodel->database().rollback();
    QMessageBox::warning(this, tr("tableModel"), tr("数据库错误：%1").arg(Tablemodel->lastError().text()),
                         QMessageBox::Ok);
    }
}

//撤销修改
void MainInterface::on_pushButton_2_clicked()
{
  Tablemodel->revertAll();
}

//查询按钮
void MainInterface::on_pushButton_7_clicked()
{
    QString Str = ui->lineEdit->text();
    //根据姓名进行筛选，一定要使用单引号
    Tablemodel->setFilter(QString::fromStdString("%1").arg(Str));
    Tablemodel->select();
}
//显示全表按钮
void MainInterface::on_pushButton_8_clicked()
{
    Tablemodel->setTable(ui->ComboBox_TableName->currentText());
    Tablemodel->select();
}

//按id升序排列按钮
void MainInterface::on_pushButton_5_clicked()
{
    //id字段，即第0列，升序排列
    Tablemodel->setSort(0, Qt::AscendingOrder);
    Tablemodel->select();
}

void MainInterface::on_pushButton_6_clicked()
{
   //按id降序排列
    Tablemodel->setSort(0, Qt::DescendingOrder);
    Tablemodel->select();
}
//删除选中行
void MainInterface::on_pushButton_4_clicked()
{
    //获取选中的行
    int curRow= ui->tableView->currentIndex().row();
    //删除该行
    Tablemodel->removeRow(curRow);
    int ok = QMessageBox::warning(this, tr("删除当前行!"),
                                  tr("你确定删除当前行吗?"), QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::No)
    {
        //如果不删除，则撤销
        Tablemodel->revertAll();
    }else{
        //否则提交，在数据库中删除该行
        Tablemodel->submitAll();

    }

}
//删除选中列
void MainInterface::on_pushButton_9_clicked()
{
    int curColumn=ui->tableView->currentIndex().column();
    //删除该列
    //model->removeColumn(curColumn);
    int ok = QMessageBox::warning(this, tr("删除当前列!"),
                                  tr("你确定删除当前列吗"),QMessageBox::Yes, QMessageBox::No);
    if(ok==QMessageBox::No)
    {
        //如果不删除，则撤销
        Tablemodel->revertAll();
    }else{
        Tablemodel->removeColumn(curColumn);

    }

}

//添加记录按钮
void MainInterface::on_pushButton_3_clicked()
{
    //获得表的行数
    int rowNum = Tablemodel->rowCount();
    int id = 10;
    //添加一行
    Tablemodel->insertRow(rowNum);
    Tablemodel->setData(Tablemodel->index(rowNum, 0), id);
    //可以直接提
    //Tablemodel->submitAll();
}


//选择数据库表
void MainInterface::on_ComboBox_TableName_currentTextChanged(const QString &arg1)
{
     extern QString LibaryName;
    if(ui->ComboBox_Chioceopeater->currentIndex()==0)
    {
    model->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(arg1));
    }else{
        Tablemodel->setTable(arg1);
        Tablemodel->select();
    }
    //查询所有列名
    QSqlQuery ColumnNamequery;
    ColumnNamequery.exec(QString("SELECT NAME FROM SYSCOLUMNS WHERE ID=OBJECT_ID('%1')").arg(arg1));
    //ColumnNamequery.exec(QString("select name from syscolumns where id=(select max(id) from sysobjects where xtype='u' and name='%1')").arg(arg1));
    QStringList ColumnNameList;
    ui->ListWidget_ColumnName_2->clear();
    ui->ListWidget_ColumnSeleced->clear();

    while(ColumnNamequery.next())
    {
        //qDebug()<<ColumnNamequery.value(0).toString();
        ColumnNameList = ColumnNamequery.value(0).toStringList();
        ui->ListWidget_ColumnName_2->addItems(ColumnNameList);
   }
    //状态标签
    //int columnscount = model->columnCount();
    //int rowcount = model->rowCount();
    //ui->label_stats_2->setText(tr("当前表总列数:%2").arg(columnscount));
}
//列名添加
void MainInterface::on_ListWidget_ColumnName_2_itemClicked(QListWidgetItem *item)
{
    if(item->isSelected()){
        ui->ListWidget_ColumnSeleced->addItem(item->text());
        int count = ui->ListWidget_ColumnSeleced->count();
        QStringList columnsname;
        QString table = ui->ComboBox_TableName->currentText();
        for(int i=0;i<count;i++)
        {
            QString colname="["""+ui->ListWidget_ColumnSeleced->item(i)->text()+"""]";
            columnsname.append(colname);
        }
        qDebug()<<columnsname.join(',');
        QString column=columnsname.join(',');
        model->setQuery(QString("select %1 from [%2].[dbo].[%3]").arg(column).arg(LibaryName).arg(table));
    }
    //状态标签
    //int columnscount = model->columnCount();
    //int rowcount = model->rowCount();
    //ui->label_stats_2->setText(tr("当前表总列数:%2").arg(columnscount));
}

//列名删除
void MainInterface::on_ListWidget_ColumnSeleced_itemClicked(QListWidgetItem *item)
{
    int row = ui->ListWidget_ColumnSeleced->currentRow();
    ui->ListWidget_ColumnSeleced->takeItem(row);
    int count = ui->ListWidget_ColumnSeleced->count();
    QStringList columnsname;
    QString table = ui->ComboBox_TableName->currentText();
    for(int i=0;i<count;i++)
    {
         QString colname="["""+ui->ListWidget_ColumnSeleced->item(i)->text()+"""]";
        columnsname.append(colname);
    }
    //qDebug()<<columnsname.join(',');
    QString column=columnsname.join(',');
    model->setQuery(QString("select %1 from [%2].[dbo].[%3]").arg(column).arg(LibaryName).arg(table));
    //状态标签
    //int columnscount = model->columnCount();
    //int rowcount = model->rowCount();
    //ui->label_stats_2->setText(tr("当前表总列数:%2").arg(columnscount));
}

//查询器设计模块模块
//选择数据库
void MainInterface::on_ComboBox_TableName_2_currentTextChanged(const QString &arg1)
{
    model1->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(arg1));
    //查询所有列名
    QSqlQuery ColumnNamequery;
    ColumnNamequery.exec(QString("SELECT NAME FROM SYSCOLUMNS WHERE ID=OBJECT_ID('%1')").arg(arg1));
    //ColumnNamequery.exec(QString("select name from syscolumns where id=(select max(id) from sysobjects where xtype='u' and name='%1')").arg(arg1));

    ui->ListWidget_ColumnName->clear();
    ui->ListWidget_ColumnSeleced_2->clear();


    while(ColumnNamequery.next())
    {
        //qDebug()<<ColumnNamequery.value(0).toString();
        QStringList ColumnNameList = ColumnNamequery.value(0).toStringList();
        ui->ListWidget_ColumnName->addItems(ColumnNameList);
    }
    //int columnscount2 = model1->columnCount();
    //ui->label_stats->setText(tr("当前表的总列数:%2").arg(columnscount2));
}

//列名添加
void MainInterface::on_ListWidget_ColumnName_itemDoubleClicked(QListWidgetItem *item)
{
    if(item->isSelected()){
        ui->ListWidget_ColumnSeleced_2->addItem(item->text());
        int count = ui->ListWidget_ColumnSeleced_2->count();
        QStringList columnsname;
        QString table = ui->ComboBox_TableName_2->currentText();
        for(int i=0;i<count;i++)
        {
             QString colname="["""+ui->ListWidget_ColumnSeleced_2->item(i)->text()+"""]";
            columnsname.append(colname);
        }
        qDebug()<<columnsname.join(',');
        QString column=columnsname.join(',');
        model1->setQuery(QString("select %1 from [%2].[dbo].[%3]").arg(column).arg(LibaryName).arg(table));
    }
    //int columnscount2 = model1->columnCount();
    //ui->label_stats->setText(tr("当前表的总列数:%2").arg(columnscount2));
}
//列名删除
void MainInterface::on_ListWidget_ColumnSeleced_2_itemClicked(QListWidgetItem *item)
{
    int row = ui->ListWidget_ColumnSeleced_2->currentRow();
    ui->ListWidget_ColumnSeleced_2->takeItem(row);
    int count = ui->ListWidget_ColumnSeleced_2->count();
    QStringList columnsname;
    QString table = ui->ComboBox_TableName_2->currentText();
    for(int i=0;i<count;i++)
    {
         QString colname="["""+ui->ListWidget_ColumnSeleced_2->item(i)->text()+"""]";
        columnsname.append(colname);
    }
    //qDebug()<<columnsname.join(',');
    QString column=columnsname.join(',');
    model1->setQuery(QString("select %1 from [%2].[dbo].[%3]").arg(column).arg(LibaryName).arg(table));
    //int columnscount2 = model1->columnCount();
    //ui->label_stats->setText(tr("当前表的总列数:%2").arg(columnscount2));
}
//添加根节点
void MainInterface::on_pushButton_10_clicked()
{

   QList<QListWidgetItem *> list= ui->ListWidget_ColumnName->selectedItems();
   if(list.isEmpty())
   {
       QMessageBox::critical(this,tr("Error!"),tr("请选择字段名和父节点!"),QMessageBox::Ok);
       return;
   }
    QString table = ui->ComboBox_TableName_2->currentText();
    QString column = ui->ListWidget_ColumnName->currentItem()->text();
    //QList<QStandardItem*>items1;
    //QStandardItem* item1 = new QStandardItem(QString::number(1));
    QStandardItem* item1 = new QStandardItem(column);
    //items1.append(item1);
    //items1.append(item2);
    treemodel->appendRow(item1);
    QSqlQuery query;

    query.exec(QString("select [%1] from [%2].[dbo].[%3]")
               .arg(column).arg(LibaryName).arg(table));
    QStringList liist;
    while(query.next())
    {
        liist.append(query.value(0).toString());
    }
for(int i=0;i<liist.size();i++)
{
    QString text=liist.at(i);
    QStandardItem* item2= new QStandardItem(text);
    item1->appendRow(item2);
}
}

//添加子节点
void MainInterface::on_pushButton_11_clicked()
{
  QModelIndex curindex= ui->treeView->currentIndex();
  if(!curindex.isValid())
        {
      QMessageBox::critical(this,tr("Error!"),tr("请选择字段名和父节点!"),QMessageBox::Ok);
      return;
  }

   QStandardItem *item = treemodel->itemFromIndex(curindex);

    if(item->child(0)==0)
     {
     QMessageBox::critical(this,tr("Error!"),tr("请选择一个有收缩框的结点!"),QMessageBox::Ok);
     return;
     }

      QList<QVariant> curtextlist= treemodel->itemData(curindex).values();
      QString curtext = curtextlist.at(0).toString();

      QString table = ui->ComboBox_TableName_2->currentText();
      QString column = ui->ListWidget_ColumnName->currentItem()->text();
      QSqlQuery query;
      query.exec(QString("select [%1] from [%2].[dbo].[%3]")
                 .arg(column).arg(LibaryName).arg(table));
      QStringList liist;
          if(item->parent()==0)
          {
              while(query.next())
              {
                  liist.append(query.value(0).toString());
              }
              int count= item->rowCount();
                  for(int j=0; j<count;j++)
                  {
                      QStandardItem *newitem = item->child(j);
                       int querynext=0;
                      // int g=item->parent()->row();
                   for(int i=0;i<liist.size();i++)
                   {    if(j==querynext)
                       {
                       QString text=liist.at(i);
                       QStandardItem* item2= new QStandardItem(text);
                       newitem->appendRow(item2);
                       querynext = querynext+1;
                   }else {
                             querynext=querynext+1;
                      }

                      }
                  }
          }
          int l=0;
      int t=0;
      QStandardItem *sitem = treemodel->itemFromIndex(curindex);
          while(sitem->parent()!=0)
          {
             l=sitem->row();
               //qDebug()<<"row"<<item->row();
              sitem=sitem->parent();
              t+=1;
//              t=sitem->rowCount();
              //qDebug()<<"rowcount"<<item->rowCount();
          }
if(item->parent()!=0){
        if(t<2)
          {
              QList<QVariant> curtextlist= treemodel->itemData(curindex).values();
          QStandardItem *item = treemodel->itemFromIndex(curindex);
              QString curtext = curtextlist.at(0).toString();
              int childcount = item->parent()->rowCount();
              QStandardItem *parent = item->parent();
              QString table = ui->ComboBox_TableName_2->currentText();
              QString column = ui->ListWidget_ColumnName->currentItem()->text();
              QSqlQuery query;
              query.exec(QString("select [%1] from [%2].[dbo].[%3]")
                         .arg(column).arg(LibaryName).arg(table));
              QStringList liist;
              while(query.next())
              {
                  liist.append(query.value(0).toString());
              }
              for(int i=0; i<childcount; i++)
              {

                  QStandardItem *ittem=parent->child(i);
                  //qDebug()<<":::::::::::::::::"<<itemname;
                  int count = ittem->rowCount();
                  for(int j=0; j<count;j++)
                  {
                      QStandardItem *newitem = ittem->child(j);
                      //qDebug()<<"!!!!!!!!!"<<curcolumn;

                         int querynext=0;
                       qDebug()<<"j"<<j;
                       for(int g=0;g<liist.size();g++)
                       {    if(i==querynext)
                           {
                           QString text=liist.at(i);
                           QStandardItem* item2= new QStandardItem(text);
                           newitem->appendRow(item2);
                           querynext = querynext+1;
                       }else {
                                 querynext=querynext+1;
                          }

                          }
                  }
}
          }


          while(sitem->parent()!=0)
          {
            // l=item->row();
               //qDebug()<<"row"<<item->row();
              item=item->parent();
              //t=item->rowCount();
              //qDebug()<<"rowcount"<<item->rowCount();
          }

          if(t>=2){
              QModelIndex curindex= ui->treeView->currentIndex();


                 QList<QVariant> curtextlist= treemodel->itemData(curindex).values();
             QStandardItem *item = treemodel->itemFromIndex(curindex);
                 QString curtext = curtextlist.at(0).toString();
                 int childcount = item->parent()->rowCount();
                 QStandardItem *parent = item->parent();
                 QString table = ui->ComboBox_TableName_2->currentText();
                 QString column = ui->ListWidget_ColumnName->currentItem()->text();
                 QSqlQuery query;
                 query.exec(QString("select [%1] from [%2].[dbo].[%3]")
                            .arg(column).arg(LibaryName).arg(table));
                 QStringList liist;
                 int l;

                 while(item->parent()!=0)
                 {
                    l=item->row();
                      qDebug()<<"row"<<item->row();
                     item=item->parent();

                     qDebug()<<"rowcount"<<item->rowCount();
                 }

             qDebug()<<"row1"<<l;
                 while(query.next())
                 {
                     liist.append(query.value(0).toString());
                 }
                 for(int i=0; i<childcount; i++)
                 {

                     QStandardItem *ittem=parent->child(i);
                     //qDebug()<<":::::::::::::::::"<<itemname;
                     int count = ittem->rowCount();
                     for(int j=0; j<count;j++)
                     {
                         QStandardItem *newitem = ittem->child(j);
                         //qDebug()<<"!!!!!!!!!"<<curcolumn;

                            int querynext=0;

                          for(int g=0;g<liist.size();g++)
                          {    if(l==g)
                              {
                              QString text=liist.at(g);
                              QStandardItem* item2= new QStandardItem(text);
                              newitem->appendRow(item2);
                              querynext =0;
                          }else {
                                    querynext=querynext+1;
                             }

                             }
                     }
                 }
          }
}
}

//删除节点
void MainInterface::on_pushButton_12_clicked()
{
     QModelIndex curindex= ui->treeView->currentIndex();

     if(!curindex.isValid())
    {
        return;
    }
    //如果没有父节点就直接删除

     QStandardItem *item = treemodel->itemFromIndex(curindex);
     int row=item->row();
if(item->parent()==0)
{
       treemodel->removeRow(curindex.row());
}
        //如果有父节点就要用父节点的takeChild删除节点
if(item->parent()!=0)
{
 item->parent()->removeRow(row);

}
}



//模块三:产能分析

void MainInterface::on_comboBox_capacity_currentTextChanged(const QString &arg1)
{
    capacityquerymodel->setQuery(QString("select * from [%1].[dbo].[%2]").arg(LibaryName).arg(arg1));

    QSqlQuery wellname;
   // wellname.exec("select "井号" from arg1");
    ui->listWidget_capacity_well->clear();
/*
    while(ColumnNamequery.next())
    {
        //qDebug()<<ColumnNamequery.value(0).toString();
        QStringList ColumnNameList = ColumnNamequery.value(0).toStringList();
        ui->ListWidget_ColumnName->addItems(ColumnNameList);
    }
    */
}
//选择井号
void MainInterface::on_listWidget_capacity_well_currentTextChanged(const QString &currentText)
{

}
