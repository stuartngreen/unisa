// Implementation file for class 'FileProcessor'.

#include "fileprocessor.h"

// Constructor.
FileProcessor::FileProcessor()
{
}

// Function to read text file contents to a string.
QString FileProcessor::readFile(QString path)
{
    QString fileDump;
    QFile file(path);

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
            fileDump.append(in.readAll());
    }
    else
    {
        qDebug() << "File could not be read.";

    }

    return fileDump;
}

// Function to remove all punctuation from a string.
QString FileProcessor::stripPunctuation(QString str) const
{
    return str.remove(QRegExp("[.,?!;:`'()<>{}[\\]\"\/\\\\]"));
}

// Function to remove all non alpha-numeric characters from a string (excl. hyphen)
QString FileProcessor::stripNonAlphaNumeric(QString str) const
{
    return str.remove(QRegExp("[^\\w\\s-]"));
}

// Return a string list of separate words.
QStringList FileProcessor::toStringList(QString str) const
{
    return str.split(QRegExp("\\s+"), QString::SkipEmptyParts);
}
