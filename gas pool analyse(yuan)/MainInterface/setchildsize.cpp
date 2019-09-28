#include "setchildsize.h"
#include "ui_setchildsize.h"
int setwidth;
int setheight;
SetChildSize::SetChildSize(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetChildSize)
{
    ui->setupUi(this);
}

SetChildSize::~SetChildSize()
{
    delete ui;
}

void SetChildSize::on_spinBox_width_valueChanged(int arg1)
{
    setwidth=arg1;
}

void SetChildSize::on_spinBox_height_valueChanged(int arg1)
{
    setheight=arg1;
}


