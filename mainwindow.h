#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void readInt(int);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();


private:
    Ui::MainWindow *ui;
    //Ui::MainWindow1 *ui1;
    //主窗口新件编辑创建的部件
    dialog *socket_dialog;
    QGroupBox *group_socket;
    QGroupBox *group_get_msg;
    QGroupBox *group_send_msg;
signals:
    void MainSignal1(int,int);
};

#endif // MAINWINDOW_H
