#include "dialog.h"
#include "ui_dialog.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QDebug>
#include "mainwindow.h"

dialog::dialog(QWidget *parent):
    QDialog(parent),
    dia(new Ui::Dialog)
{
//    dia = new QDialog(parent);
    dia->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose,true);//设置关闭就自动删除，不需要主动调用delete函数；设置该属性后该类必须用new来实例化
    setWindowModality(Qt::WindowModality::NonModal);//设置窗口非模态
}

dialog::~dialog()
{
    if(NULL!=dia)
    {
        delete dia;
        dia=NULL;
    }
}

bool dialog::dia_tcp_client(){
    //创建子窗口
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("dia"));
    return false;
}

void dialog::on_pushButton_2_clicked()
{
    dia->pushButton->setText("唐");
}

void dialog::on_pushButton_3_clicked()
{
    emit(sendInt(6));
}
void dialog::diaRead(int a,int b)
{
    dia->lineEdit->setText(QString::number((a+b)));
}
