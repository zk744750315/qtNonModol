#ifndef Dialog_H
#define Dialog_H

#include <QDialog>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
class MainWindow;
namespace  Ui{
class Dialog;
}

class dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = 0);
    ~dialog();
    bool dia_tcp_client();

private:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    Ui::Dialog *dia;
    QPushButton *btn_cel;
    MainWindow* mainWindow;



signals:
    //void enter_tcpclient();
    int sendInt(int);
public slots:
    void diaRead(int a,int b);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // Dialog_H
