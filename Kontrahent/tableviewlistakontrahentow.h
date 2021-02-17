#ifndef TABLEVIEWLISTAKONTRAHENTOW_H
#define TABLEVIEWLISTAKONTRAHENTOW_H
#include <QAbstractTableModel>
#include <QWidget>

class TableViewListaKontrahentow : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableViewListaKontrahentow(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // TABLEVIEWLISTAKONTRAHENTOW_H
    //Info do Gita