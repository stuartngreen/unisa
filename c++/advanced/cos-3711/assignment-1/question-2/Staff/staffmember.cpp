// Implementation file for class 'StaffMember'.

#include "staffmember.h"

// Constructor.
StaffMember::StaffMember(QString name, QDate date, ApptType type)
{
    this->setProperty("Name", name);
    this->setProperty("Birth_Date", date);
    this->setProperty("Appointment_Type", type);
}

// Getters.
QString StaffMember::getName() const
{
    return m_Name;
}

QDate StaffMember::getBirthDate() const
{
    return m_BirthDate;
}

StaffMember::ApptType StaffMember::getApptType() const
{
    return m_ApptType;
}

// Setters.
void StaffMember::setName(QString name)
{
    m_Name = name;
}

void StaffMember::setBirthDate(QDate date)
{
    m_BirthDate = date;
}

void StaffMember::setApptType(StaffMember::ApptType type)
{
    m_ApptType = type;
}

// Overloaded setter which accepts a string.
void StaffMember::setApptType(QString type)
{
    // Use the metaObject to get enum property
    static const QMetaObject* metaObj = metaObject();
    int i = metaObj->indexOfProperty("Appointment_Type");
    QMetaProperty metaProp = metaObj->property(i);
    QMetaEnum metaEnum = metaProp.enumerator();

    // Convert QString to char*
    char* key = type.toLatin1().data();

    // Get enum value from key and set the data member.
    StaffMember::ApptType apptType = static_cast<StaffMember::ApptType>(metaEnum.keyToValue(key));
    m_ApptType = apptType;
}
