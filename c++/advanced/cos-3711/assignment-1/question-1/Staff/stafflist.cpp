// Implementation file for class 'StaffList'.

#include "stafflist.h"

// Constructor.
StaffList::StaffList()
{
}

// Destructor.
StaffList::~StaffList()
{
    qDebug() << "Destroying StaffList...";
    qDeleteAll(m_StaffList);
}

// Function to append a staff member object to the list.
void StaffList::addStaffMember(StaffMember *staff)
{
    m_StaffList.append(staff);
}

// Function to return the whole list of staff members as a string.
QString StaffList::toString() const
{
    QString s;
    for (int i = 0; i < m_StaffList.size(); i++)
        s.append(m_StaffList[i]->toString() + "\n");

    return s;
}
