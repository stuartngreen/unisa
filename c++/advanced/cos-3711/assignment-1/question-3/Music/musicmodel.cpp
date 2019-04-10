// Implementation file for class 'MusicModel'.

#include "musicmodel.h"

// Constructor.
MusicModel::MusicModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Destructor.
MusicModel::~MusicModel()
{
}

// Reimplemented function to return amount of rows.
int MusicModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_Data.size();
}

// Reimplemented function to return amount of columns.
int MusicModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4;
}

// Reimplemented function to return data in the model.
QVariant MusicModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= m_Data.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        const MusicItem musicItem = m_Data.at(index.row());

        if (index.column() == 0)
            return musicItem.composer;
        else if (index.column() == 1)
            return musicItem.title;
        else if (index.column() == 2)
            return musicItem.cost;
        else if (index.column() == 3)
            return musicItem.rating;
    }

    return QVariant();
}

// Reimplemented function to return header labels.
QVariant MusicModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    // Return the headings for the table view.
    if (section == 0)
        return QString("Composer");
    else if (section == 1)
        return QString("Album Title");
    else if (section == 2)
        return QString("Replacement Cost (R)");
    else if (section == 3)
        return QString("Rating");
    else
        return QVariant();

    return QVariant();
}

// Function required for an editable model.
bool MusicModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        int row = index.row();
        MusicItem musicItem = m_Data.value(row);

        // Set composer data.
        if (index.column() == 0)
            musicItem.composer = value.toString();

        // Set album title data.
        else if (index.column() == 1)
            musicItem.title = value.toString();

        // Set replacement cost data.
        else if (index.column() == 2)
        {
            if (value.toFloat() >= 0)
                musicItem.cost = value.toFloat();
        }

        // Set rating data.
        else if (index.column() == 3)
        {
            if (value.toInt() <= 100 && value.toInt() >= 0)
                musicItem.rating = value.toInt();
        }
        else
            return false;

        // Update the table row with edited info.
        m_Data.replace(row, musicItem);
        return true;
    }

    return false;
}

Qt::ItemFlags MusicModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return QAbstractTableModel::flags(index) | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    else
        return 0;
}

// Function to append a MusicItem to the QList data member in the model.
void MusicModel::insertData(MusicItem item)
{
    int row = m_Data.size();
    beginInsertRows(QModelIndex(), row + 1, row + 1);
    m_Data.append(item);
    endInsertRows();
}
