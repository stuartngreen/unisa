// Implementation file for class 'WordCounter'.

#include "wordcounter.h"

// Constructor.
WordCounter::WordCounter(QStringList* list)
{
    m_List = list;
}

// Return count of words longer than 4 characters that begin with a capital letter (includes hyphenated words)
int WordCounter::countStartWithCap()
{
    return countWords(QRegExp("^[A-Z](\\w+(-\\w+)*){4,}"));
}

// Return count of hyphenated words.
int WordCounter::countHyphenated()
{
    return countWords(QRegExp("^\\w+(-\\w+)+"));
}

// Return count of words that begin and end with the same alpha-numeric character.
int WordCounter::countSameStartEnd()
{
    return countWords(QRegExp("(\\w)\\w*(-\\w+)*\\1"));
}

// Return count of words that do not start with a vowel.
int WordCounter::countNoVowelStart()
{
    return countWords(QRegExp("^[^AEIOUaeiou]\\w+(-\\w+)*"));
}

// Count the words matching the regular expression.
int WordCounter::countWords(QRegExp regex)
{
    int count = 0;

    for (int i = 0; i < m_List->size(); i++)
    {
        QString word = m_List->at(i);
        if (regex.exactMatch(word))
        {
            //qDebug() << word;
            count++;
        }
    }

    return count;
}
