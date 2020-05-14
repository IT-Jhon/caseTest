#ifndef CASEMODEL_H
#define CASEMODEL_H

#include <QAbstractTableModel>

class CaseModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit CaseModel(QObject *parent = 0);

    void refrushModel();

    virtual int rowCount(const QModelIndex &parent= QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent= QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QStringList m_header;
};

#endif // CASEMODEL_H
