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
    QString str;

    // For each staff member object, output to string and append.
    for (int i = 0; i < m_StaffList.size(); i++)
    {
        ObjectOutput output;
        StaffMember* staff = m_StaffList[i];
        str.append(output.objectToString(staff) + "\n");
    }

    return str;
}
