// Interface file for class 'StaffList' which represents a list of StaffMember objects. There is a:
//  - default constructor,
//  - destructor,
//  - addStaffMember function which appends a staff member object to the list.
//  - toString function to return the whole list of staff members as a string.

#ifndef STAFFLIST_H
#define STAFFLIST_H

#include <QList>
#include <QString>
#include <QDebug>
#include "staffmember.h"
#include "objectoutput.h"

class StaffList
{
public:
    StaffList();
    ~StaffList();
    void addStaffMember(StaffMember *staff);
    QString toString() const;

private:
    QList<StaffMember*> m_StaffList;
};

#endif // STAFFLIST_H
