#include "casemodel.h"
#include "globalvars.h"

#include <QDebug>

CaseModel::CaseModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_header << "编号"<<"案件类型"<<"名称"<<"立案条件";
}

int CaseModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

int CaseModel::rowCount(const QModelIndex &parent) const
{
    return GlobalVars::g_caseInfoList->length();
}

QVariant CaseModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
        case 0:
            return GlobalVars::g_caseInfoList->at(index.row()).getID(); break;
        case 1:
            return GlobalVars::g_caseInfoList->at(index.row()).getCaseType(); break;
        case 2:
            return GlobalVars::g_caseInfoList->at(index.row()).getName(); break;
        case 3:
            return GlobalVars::g_caseInfoList->at(index.row()).getCaseCondit(); break;
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant CaseModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole && orientation==Qt::Horizontal)
    {
        return m_header[section];
    }
    return QAbstractTableModel::headerData(section,orientation,role);
}

void CaseModel::refrushModel()
{
    beginResetModel();
    endResetModel();
}

