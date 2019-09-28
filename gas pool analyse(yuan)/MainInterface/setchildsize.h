#ifndef SETCHILDSIZE_H
#define SETCHILDSIZE_H

#include <QWidget>

namespace Ui {
class SetChildSize;
}
class SetChildSize : public QWidget
{
    Q_OBJECT

public:
    explicit SetChildSize(QWidget *parent = 0);
    ~SetChildSize();

private slots:
    void on_spinBox_width_valueChanged(int arg1);

    void on_spinBox_height_valueChanged(int arg1);



private:
    Ui::SetChildSize *ui;


};
extern int setheight;
extern int setwidth;
#endif // SETCHILDSIZE_H
