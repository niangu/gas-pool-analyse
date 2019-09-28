#ifndef MYMDI_H
#define MYMDI_H

#include <QMainWindow>
class QMdiSubWindow;
class QTableView;
class QTreeView;
class SetChildSize;
namespace Ui {
class MyMdi;

}

class MyMdi : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMdi(QWidget *parent = 0);
    ~MyMdi();
QTableView *addtablewindow();
 QTreeView *addtreewindow();
//bool eventFilter(QObject *watched, QMouseEvent *event);
private:
    Ui::MyMdi *ui_mymdi;
   QMdiSubWindow *tablechild;
     QMdiSubWindow *treechild=NULL;
     // SetChildSize *setsize;
   bool mDragWindow=false;
   bool mChildWindow=false;

   QPoint mMousePoint;

   void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


};

#endif // MYMDI_H
