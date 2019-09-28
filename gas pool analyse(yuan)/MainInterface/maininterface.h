#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>

class QSqlTableModel;
class QSqlQueryModel;
class QListWidgetItem;
class QTreeWidgetItem;
class QStandardItemModel;
class QStandardItem;
class QTableView;
class QTreeView;
class MyMdi;
namespace Ui {
class MainInterface;
//class MyMdi;
}

class MainInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainInterface(QWidget *parent = nullptr);
    ~MainInterface();

private slots:
    void on_action_connection_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_ComboBox_TableName_currentTextChanged(const QString &arg1);

    void on_ComboBox_TableName_2_currentTextChanged(const QString &arg1);

    void on_ListWidget_ColumnName_2_itemClicked(QListWidgetItem *item);

    void on_ListWidget_ColumnSeleced_itemClicked(QListWidgetItem *item);

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();



    void on_ComboBox_Chioceopeater_currentIndexChanged(int index);

    void on_ListWidget_ColumnName_itemDoubleClicked(QListWidgetItem *item);

    void on_ListWidget_ColumnSeleced_2_itemClicked(QListWidgetItem *item);

    void on_action_triggered();

    void on_comboBox_currentIndexChanged(int index);

    void on_toolBox_currentChanged(int index);

    void on_action_2_triggered();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_action_open_triggered();

    void on_comboBox_capacity_currentTextChanged(const QString &arg1);

    void on_listWidget_capacity_well_currentTextChanged(const QString &currentText);

private:
    Ui::MainInterface *ui;
   // Ui::MyMdi *ui_mymdi;
    QSqlTableModel *Tablemodel;
    QSqlQueryModel *model;
    QSqlQueryModel *model1;
    QStandardItemModel *treemodel;
    QSqlQueryModel *capacityquerymodel;
    QString ColumnsName;
    QTableView *table=NULL;
    QTreeView *tree=NULL;
    MyMdi *mymdi;
};
//extern QString LibaryName;
#endif // MAININTERFACE_H
