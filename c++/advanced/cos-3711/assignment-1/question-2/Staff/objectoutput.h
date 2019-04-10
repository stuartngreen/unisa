// Interface file for class 'ObjectOutput' which writes objects to a text file.
// There is a:
//  - default constructor and constructor which accepts a file name,
//  - objectToString function to return a QObject's contents as a string,
//  - saveToFile function which writes a provided QObject to a text file.

#ifndef OBJECTOUTPUT_H
#define OBJECTOUTPUT_H

#include <QFile>
#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>
#include <QTextStream>
#include <QDate>
#include <QDebug>

class ObjectOutput
{
public:
    ObjectOutput();
    ObjectOutput(QString fileName);
    QString objectToString(const QObject* obj);
    bool saveToFile(const QObject* obj);

private:
    QString m_FileName;
};

#endif // OBJECTOUTPUT_H
