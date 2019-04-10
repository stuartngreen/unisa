// Interface file for class 'StaffOutput' which writes staff member objects to a text file.
// There is a:
//  - default constructor and constructor which accepts a file name,
//  - saveToFile function which appends new staff member information to a text file.

#ifndef STAFFOUTPUT_H
#define STAFFOUTPUT_H

#include <QFile>
#include <QTextStream>
#include "staffmember.h"

class StaffOutput
{
public:
    StaffOutput();
    StaffOutput(QString fileName);
    bool saveToFile(const StaffMember* staff);

private:
    QString m_FileName;
};

#endif // STAFFOUTPUT_H
