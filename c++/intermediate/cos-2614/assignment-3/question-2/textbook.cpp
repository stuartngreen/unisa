// Implementation file for class Textbook.

#include "textbook.h"

// Constructor.
Textbook::Textbook(QString title, QString author, QString isbn, uint year) :
    m_Title(title), m_Author(author), m_Isbn(isbn), m_YearPub(year)
{

}

// Destructor.
Textbook::~Textbook()
{
    qDebug() << "Destroying Textbook ...";
}

// Get author.
QString Textbook::getAuthor() const
{
    return m_Author;
}

// Get title.
QString Textbook::getTitle() const
{
    return m_Title;
}

// Get ISBN number.
QString Textbook::getIsbn() const
{
    return m_Isbn;
}

// Get year published.
uint Textbook::getYearPub() const
{
    return m_YearPub;
}

// Return formatted string for textbook info.
QString Textbook::toString() const
{
    return QString("Title: %1\nAuthor: %2\nISBN No.: %3\nYear Published: %4")
            .arg(m_Title)
            .arg(m_Author)
            .arg(m_Isbn)
            .arg(m_YearPub);
}

// Set title.
void Textbook::setTitle(const QString& newTitle)
{
    m_Title = newTitle;
}

// Set ISBN number.
void Textbook::setIsbn(const QString& newIsbn)
{
    m_Isbn = newIsbn;
}

// Set year published.
void Textbook::setYearPub(uint newYear)
{
    m_YearPub = newYear;
}

// Set author.
void Textbook::setAuthor(const QString& newAuthor)
{
    m_Author = newAuthor;
}
