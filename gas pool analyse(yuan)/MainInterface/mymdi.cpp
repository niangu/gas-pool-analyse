#include "mymdi.h"
#include "ui_mymdi.h"
#include"maininterface.h"
#include<QTableView>
#include<QMdiSubWindow>
#include<QTreeView>
#include<QMouseEvent>



MyMdi::MyMdi(QWidget *parent) :
    QMainWindow(parent),
    ui_mymdi(new Ui::MyMdi)
{
    ui_mymdi->setupUi(this);
    setWindowFlag(Qt::WindowStaysOnTopHint,false);
    setWindowFlag(Qt::FramelessWindowHint,true);//添加设置
    hasMouseTracking();
   // setsize=new SetChildSize;
   //setsize->show();

}

MyMdi::~MyMdi()
{
    delete ui_mymdi;

}

QTableView *MyMdi::addtablewindow()
{
    QTableView *table = new QTableView(this);
    tablechild = ui_mymdi->mdiArea->addSubWindow(table);
    //tablechild->setWindowFlag(Qt::FramelessWindowHint,true);
    table->show();


    return table;
}

QTreeView *MyMdi::addtreewindow()
{
    QTreeView *tree = new QTreeView(this);
    treechild = ui_mymdi->mdiArea->addSubWindow(tree);
// treechild->setWindowFlag(Qt::FramelessWindowHint,true);
 treechild->show();
    return tree;
}


void MyMdi::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        mMousePoint = event->globalPos()-this->pos();
        event->accept();
        mDragWindow=true;
        mChildWindow=false;
    }
    if(event->button()==Qt::RightButton)
    {
        mChildWindow=true;
    }
    }


void MyMdi::mouseReleaseEvent(QMouseEvent *event)
{
    mDragWindow=false;
}

void MyMdi::mouseMoveEvent(QMouseEvent *event)
{
    if(mDragWindow&&event->buttons()&&Qt::LeftButton)
    {
        this->move(event->globalPos()-mMousePoint);
        event->accept();

    }
/*
    if(mChildWindow&&event->buttons()&&Qt::RightButton)
    {
        if(tablechild!=NULL){
       QWidget *sub=previousInFocusChain();
        int width=tablechild->width();
       int height=tablechild->height();
       //int height=setheight;
       //int width=setwidth;

            tablechild->setGeometry(event->pos().x(),event->pos().y(),width,height);


        }

    }

*/
}



