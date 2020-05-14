#ifndef CASEFORM_H
#define CASEFORM_H

#include <QWidget>
#include "casemodel.h"

namespace Ui {
class CaseForm;
}

class CaseForm : public QWidget
{
    Q_OBJECT

public:
    explicit CaseForm(QWidget *parent = 0);
    ~CaseForm();

    enum Search_Condition{
        Search_None = 0,
        Search_ID,
        Search_Type,
        Search_Name
    };

private slots:
    void on_pb_add_clicked();

    void on_pb_search_clicked();

    void on_cb_condition_currentIndexChanged(int index);

    void on_pb_save_clicked();

    void on_pb_cancel_clicked();

    void on_pb_modify_clicked();

    void on_pb_delete_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::CaseForm *ui;
    CaseModel *m_model;

    int m_operData;
    int m_searchCond;

    void initWidgetUnits(void);
};

#endif // CASEFORM_H
