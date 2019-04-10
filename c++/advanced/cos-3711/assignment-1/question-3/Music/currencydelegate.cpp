// Implementation file for class 'CurrencyDelegate'.

#include "currencydelegate.h"

// Constructor.
CurrencyDelegate::CurrencyDelegate()
{
}

// Function which specifies the format to return for currencies.
QString CurrencyDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    double currency = value.toDouble();
    return locale.toString(currency, 'f', 2);
}

// Function to set the alignment of the cell.
void CurrencyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    opt.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
    QStyledItemDelegate::paint(painter, opt, index);
}
