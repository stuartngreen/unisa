// Interface file for class 'FileProcessor' which reads file contents and
// creates a list of cleaned up words.
// There is a:
//  - constructor,
//  - readFile function to read text file contents to a string,
//  - stripPunctuation function to remove all punctuation from a string,
//  - stripNonAlphaNumeric function to remove all non alpha-numeric characters
//    from a string (excl. hyphen),
//  - toStringList function to return a string list of separate words.

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>

class FileProcessor
{
public:
    FileProcessor();
    QString readFile(QString path);
    QString stripPunctuation(QString str) const;
    QString stripNonAlphaNumeric(QString str) const;
    QStringList toStringList(QString str) const;
};

#endif // FILEPROCESSOR_H
