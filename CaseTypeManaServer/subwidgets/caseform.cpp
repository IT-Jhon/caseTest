#include "caseform.h"
#include "ui_caseform.h"
#include "globalvars.h"
#include "execsql.h"

#include <QDebug>

CaseForm::CaseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaseForm)
{
    ui->setupUi(this);

    m_operData = Oper_None;
    m_searchCond = Search_None;

    initWidgetUnits();
    m_model = new CaseModel(this);


    ExecSQL::searchAllUserInfos();
    on_pb_search_clicked();

    ui->tableView->setModel(m_model);
}

CaseForm::~CaseForm()
{
    delete ui;
}

void CaseForm::initWidgetUnits(void)
{
    ui->le_caseCondition->setEnabled(false);
    ui->le_id->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_caseType->setEnabled(false);
    ui->le_caseCondition->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void CaseForm::on_pb_add_clicked()
{
    m_operData = Oper_Add;
    ui->le_id->setEnabled(true);
    ui->le_name->setEnabled(true);
    ui->le_caseType->setEnabled(true);
    ui->le_caseCondition->setEnabled(true);
    ui->pb_add->setEnabled(true);
    ui->pb_save->setEnabled(true);

    m_model->refrushModel();
}

void CaseForm::on_pb_search_clicked()
{
    if(m_searchCond == Search_ID)
    {
        ExecSQL::searchCaseInfoForID(ui->le_condition->text());
    }else if (m_searchCond == Search_Type)
    {
        ExecSQL::searchCaseInfoForType(ui->le_condition->text());
    }else if (m_searchCond == Search_Name)
    {
        ExecSQL::searchCaseInfoForName(ui->le_condition->text());
    }else
    {
        ExecSQL::searchAllCaseInfos();
    }
    m_model->refrushModel();
}


void CaseForm::on_cb_condition_currentIndexChanged(int index)
{
    m_searchCond = index;

    if(m_searchCond == Search_None)
    {
        ui->le_condition->setEnabled(false);
    }else
    {
        ui->le_condition->setEnabled(true);
    }
}

void CaseForm::on_pb_save_clicked()
{
    if(m_operData == Oper_Add)
    {
        CaseInfo info(ui->le_id->text(), ui->le_caseType->text(),
                      ui->le_name->text(), ui->le_caseCondition->text());
        ExecSQL::addNewCaseInfo(info);
    }else if (m_operData == Oper_Del)
    {
        ExecSQL::removeCaseInfo(ui->le_id->text());
    }else
    {
        ExecSQL::modifyCaseInfoForType(ui->le_id->text(), ui->le_caseType->text());
        ExecSQL::modifyCaseInfoForName(ui->le_id->text(), ui->le_name->text());
        ExecSQL::modifyCaseInfoForCondit(ui->le_id->text(), ui->le_caseCondition->text());
    }

    on_pb_search_clicked();
}

void CaseForm::on_pb_cancel_clicked()
{
    ui->le_id->clear();
    ui->le_caseType->clear();
    ui->le_name->clear();
    ui->le_caseCondition->clear();

    ui->le_id->setEnabled(false);
    ui->le_caseType->setEnabled(false);
    ui->le_name->setEnabled(false);
    ui->le_caseCondition->setEnabled(false);
    ui->pb_save->setEnabled(false);
}

void CaseForm::on_pb_modify_clicked()
{
    m_operData = Oper_Mdy;

    ui->le_caseType->setEnabled(true);
    ui->le_name->setEnabled(true);
    ui->le_caseCondition->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void CaseForm::on_pb_delete_clicked()
{
    m_operData = Oper_Del;

    ui->le_id->setEnabled(true);
    ui->le_caseType->setEnabled(true);
    ui->le_name->setEnabled(true);
    ui->le_caseCondition->setEnabled(true);
    ui->pb_save->setEnabled(true);
}

void CaseForm::on_tableView_clicked(const QModelIndex &index)
{
    const CaseInfo info = GlobalVars::g_caseInfoList->at(index.row());

    ui->le_id->setText(info.getID());
    ui->le_caseType->setText(info.getCaseType());
    ui->le_name->setText(info.getName());
    ui->le_caseCondition->setText(info.getCaseCondit());
}
