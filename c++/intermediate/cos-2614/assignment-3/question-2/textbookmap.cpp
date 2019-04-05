// Implementation file for class TextbookMap.

#include "textbookmap.h"

// Destructor.
TextbookMap::~TextbookMap()
{
    qDebug() << "Destroying TextbookMap ..." << endl;
    qDeleteAll(values());
    clear();
}

// Return string of all map contents.
QString TextbookMap::toString() const
{
    QString str;
    QTextStream out(&str);
    ConstIterator itr;

    for (itr = this->constBegin(); itr != this->constEnd(); ++itr)
    {
        out << "[" << itr.key() << "]" << endl;
        out << itr.value()->toString() << endl << endl;
    }
    return str;
}

// Add textbook to map.
void TextbookMap::add(Textbook* text)
{
    insert(text->getIsbn(), text);
}

// Delete textbook from map.
void TextbookMap::deleteTextbook(QString isbn)
{
    Iterator itr;
    for (itr = this->begin(); itr != this->end();)
    {
        if (itr.key() == isbn)
        {
            delete itr.value(); // delete object
            itr = this->erase(itr);
        }
        else
            ++itr;
    }
}

// Function to search for matching key (ISBN) and return true if found.
bool TextbookMap::foundTextbook(QString isbn) const
{
    bool found = false;
    ConstIterator itr;

    for (itr = this->constBegin(); itr != this->constEnd(); ++itr)
    {
        if (itr.key() == isbn)
            found = true;
    }
    return found;
}

// Return list of strings of textbooks for matching author.
QStringList TextbookMap::textbookInfo(QString author) const
{
    QStringList bookList;

    foreach (Textbook* t, values())
    {
        if (t->getAuthor().toUpper() == author.toUpper())
            bookList.append(t->toString()); // append each match to list
    }

    return bookList;
}
