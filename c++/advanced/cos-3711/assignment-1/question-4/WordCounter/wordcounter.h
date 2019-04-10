// Interface file for class 'WordCounter' which counts words based on a provided regular
// expression. There is a:
//  - constructor which accepts a string list,
//  - countStartWithCap function to count words longer than 4 characters that begin with
//    a capital letter (includes hyphenated words),
//  - countHyphenated function to count hyphenated words,
//  - countSameStartEnd function to count words that begin and end with the same alpha-
//    numeric character,
//  - countNoVowelStart function to count words that do not start with a vowel,
//  - countWords function used by the functions above to count the words matching the
//    regular expression provided.

#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <QStringList>
#include <QDebug>

class WordCounter
{
public:
    WordCounter(QStringList* list);
    int countStartWithCap();
    int countHyphenated();
    int countSameStartEnd();
    int countNoVowelStart();
    int countWords(QRegExp regex);

private:
    QStringList* m_List;
};

#endif // WORDCOUNTER_H
