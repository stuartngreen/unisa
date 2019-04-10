// Interface file for class 'XmlOutput' which builds the XML hierarchy for a StudentList
// and outputs it to a file. There is a:
// - constructor,
// - outputXml() function to write the XML to a file,
// - buildXml() function to build the required XML structure from the list.

#ifndef XMLOUTPUT_H
#define XMLOUTPUT_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDomDocument>
#include "studentlist.h"

class XmlOutput
{
public:
    XmlOutput();
    bool outputXml(QString filename);
    QString buildXml();
};

#endif // XMLOUTPUT_H
