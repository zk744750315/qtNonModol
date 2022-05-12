#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //主窗口中要显示的控件创建出来
    setWindowModality(Qt::WindowModality::NonModal);
    group_socket = new QGroupBox(this);
    group_socket->setHidden(true);

    group_get_msg = new QGroupBox(this);
    group_get_msg->setHidden(true);
    group_send_msg = new QGroupBox(this);
    group_send_msg->setHidden(true);

  //  group_graph = new QGroupBox(this);
  //  group_graph->setHidden(true);

}

MainWindow::~MainWindow()
{
    //删除所有部件，顺序要先删除子类部件，在删除父类部件，否则会造成野指针，但是socket_dialog设置了：
    //etAttribute(Qt::WA_DeleteOnClose)关闭自动回收功能,不需要调用delete
//    if(NULL!=socket_dialog)
//    {
//        qDebug()<<socket_dialog;
//        delete socket_dialog;
//        socket_dialog = NULL;
//    }
    delete group_socket;
    delete group_get_msg;
    delete group_send_msg;
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{

    qDebug()<<3;
    socket_dialog = new dialog( );//此处不设置dialog的父类，dialog窗口弹出后会显示在主窗口前面。若要设置父类采用： new dialog(this)。
    qDebug()<<2;
    socket_dialog->setModal(false);//设置为非模态
    //socket_dialog->getMainWindow(this);
    connect(this,&MainWindow::MainSignal1,socket_dialog,&dialog::diaRead);   //发出信号相应
    socket_dialog->show();
    connect(socket_dialog,&dialog::sendInt,this,&MainWindow::readInt);   //发出信号相应
    if(!socket_dialog->dia_tcp_client())
    {

        return;
    }
    else{
        //主窗口部件布局设计

        //注意区域的划分，是放在底层的，也就是说，代码的顺序是要放在前面的
        //区域的划分
        group_socket->setTitle(tr("Socket Message"));
        group_socket->setHidden(false);
        group_socket->setGeometry(QRect(150,10,500,80));
        }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setText("abc");
}
void MainWindow::readInt(int t)
{
    ui->lineEdit->setText(QString::number(t));
}


void MainWindow::on_pushButton_4_clicked()
{
    emit(MainSignal1(4,5));
}
