#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginform.h"
#include "caseform.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //窗体标题
    this->setWindowTitle("案件类型管理子系统");
    //窗体 ICO图片，如图不起别名，后缀直接写图片全名。
    this->setWindowIcon(QIcon(":/images/logo01.jpg"));

    m_loginForm = new LoginForm(ui->widget);
    m_caseForm = new CaseForm(ui->widget);

    connect(m_loginForm, SIGNAL(signalUserLogin(QString,QString)),
            this, SLOT(slotUserLogin(QString,QString)));

    m_loginForm->show();
    m_caseForm->hide();


    /////////////////和UI设计角度有关，都是为了登陆界面   对action和widget类要有认识//////////////////////////////////////////////////////
    ui->mainToolBar->hide();
    ui->menuBar->hide();
    ui->statusBar->hide();
    this->setContextMenuPolicy(Qt::NoContextMenu); //去掉工具栏的右键菜单
    this->setCentralWidget(ui->widget);            //将给定的小部件设置为主窗口的中心小部件。
                                                   //注意:QMainWindow接受小部件指针的所有权，并在适当的时候删除它。
    m_msgsrver = new MsgServer;

}

MainWindow::~MainWindow()
{
    delete m_msgsrver;
    delete ui;
}


void MainWindow::slotUserLogin(QString id, QString pswd)
{
    if((id == "Ad-101") && (pswd == "123456"))
    {
        qDebug() << "验证通过";

        ui->mainToolBar->show();
        on_actionCase_triggered();
    }else{
        qDebug()<<"信息有误登陆失败";

        m_loginForm->userLoginFail();
    }
}

void MainWindow::on_actionCase_triggered()
{
    m_loginForm->hide();
    m_caseForm->show();

    ui->actionCase->setEnabled(false);
    ui->actionUser->setEnabled(true);
    ui->actionWorkflow->setEnabled(true);
    ui->actionWarning->setEnabled(true);
}

void MainWindow::on_actionUser_triggered()
{
    m_loginForm->hide();
    m_caseForm->hide();

    ui->actionCase->setEnabled(true);
    ui->actionUser->setEnabled(false);
    ui->actionWorkflow->setEnabled(true);
    ui->actionWarning->setEnabled(true);
}


void MainWindow::on_actionWorkflow_triggered()
{
    m_loginForm->hide();
    m_caseForm->hide();

    ui->actionCase->setEnabled(true);
    ui->actionUser->setEnabled(true);
    ui->actionWorkflow->setEnabled(false);
    ui->actionWarning->setEnabled(true);
}

void MainWindow::on_actionWarning_triggered()
{
    m_loginForm->hide();
    m_caseForm->hide();

    ui->actionCase->setEnabled(true);
    ui->actionUser->setEnabled(true);
    ui->actionWorkflow->setEnabled(true);
    ui->actionWarning->setEnabled(false);
}
