// Header file for class TextbookMap, derived from QMap. There is a:
//  - destructor,
//  - toString() function to return a string of all the map contents,
//  - functions to add and delete textbooks,
//  - bool foundTextbook() function to check if a textbook is in the map,
//  - textbookInfo function to return a QStringList of books by provided author.

#ifndef TEXTBOOKMAP_H
#define TEXTBOOKMAP_H

#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QMap>
#include "textbook.h"

class TextbookMap : public QMap<QString, Textbook*>
{
public:
    ~TextbookMap();
    QString toString() const;
    void add(Textbook* text);
    void deleteTextbook(QString isbn);
    bool foundTextbook(QString isbn) const;
    QStringList textbookInfo(QString author) const;
};

#endif // TEXTBOOKMAP_H
