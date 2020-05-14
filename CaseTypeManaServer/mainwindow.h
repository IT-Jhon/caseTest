#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "msgserver.h"
#include "msgsocket.h"

class LoginForm;
class CaseForm;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void slotUserLogin(QString id, QString pswd);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionCase_triggered();

    void on_actionUser_triggered();

    void on_actionWorkflow_triggered();

    void on_actionWarning_triggered();

private:
    Ui::MainWindow *ui;
    LoginForm *m_loginForm;
    CaseForm *m_caseForm;

    MsgServer *m_msgsrver;
};

#endif // MAINWINDOW_H
