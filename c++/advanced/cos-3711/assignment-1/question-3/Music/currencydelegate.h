// Interface file for class 'CurrencyDelegate' which specifies the format for
// currencies. There is a:
//  - Constructor,
//  - displayText function which specifies the format to return for currencies,
//  - paint function to set the alignment of the cell.

#ifndef CURRENCYDELEGATE_H
#define CURRENCYDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class CurrencyDelegate : public QStyledItemDelegate
{
public:
    CurrencyDelegate();
    virtual QString displayText(const QVariant &value, const QLocale &locale) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // CURRENCYDELEGATE_H
