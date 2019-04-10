// Implementation file for class 'StaffOutput'.

#include <QDataStream>
#include <QDebug>
#include "staffoutput.h"

// Constructors.
StaffOutput::StaffOutput() : m_FileName("output.txt")
{
}

StaffOutput::StaffOutput(QString fileName) : m_FileName(fileName)
{
}

// Function to append new staff member information to a text file.
bool StaffOutput::saveToFile(const StaffMember* staff)
{
    QFile file(m_FileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream out(&file);
        out << staff->toString();
        file.close();
        return true;
    }
    return false;
}
