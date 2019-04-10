// Interface file for class 'MusicModel' which inherits from QAbstractTableModel and uses
// a QList to store struct MusicItem. The MusicItem struct represents information about a
// music CD and comprises of Composer, Title, Cost and Rating. There is a:
//  - Constructor,
//  - rowCount and columnCount functions to return amount of items in the QList, and
//    amount of columns for properties in the MusicItem struct,
//  - data and headerData functions to return the values and headings for the MusicModel,
//  - setData function and flags required for an editable model,
//  - insertData function to append a MusicItem to the QList data member.

#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QDebug>

struct MusicItem
{
    QString composer;
    QString title;
    float cost;
    int rating;
};

class MusicModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    MusicModel(QObject *parent = 0);
    ~MusicModel();

    // Must implement the following when subclassing QAbstractTableModel.
    // Information found here: http://doc.qt.io/qt-5/qabstracttablemodel.html#subclassing

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    // For an editable model implement these.
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    // Function to insert data into model.
    void insertData(MusicItem item);

private:
    QList<MusicItem> m_Data;
};

#endif // MUSICMODEL_H
