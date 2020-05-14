#include "loginform.h"
#include "ui_loginform.h"

#include <QPaintEvent>
#include <Qpainter>
#include <QPixmap>
#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    //窗体标题
    this->setWindowTitle("案件类型管理子系统");
    //窗体 ICO图片，如图不起别名，后缀直接写图片全名。
    this->setWindowIcon(QIcon(":/images/logo01.jpg"));
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPixmap pix(":/images/logo_back03.jpg");
    p.drawPixmap(0,0,610, 450, pix);
}

void LoginForm::on_pb_login_clicked()
{
    emit signalUserLogin(ui->le_userid->text(),
                         ui->le_pswd->text());
}

void LoginForm::userLoginFail()
{
    QMessageBox msgBox(this);
    msgBox.setStyleSheet("border-image: rgb(85, 49, 208);");
    msgBox.setText("登陆失败");
    msgBox.exec();
}


