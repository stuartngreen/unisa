// Implementation file for class 'StaffMember'.

#include "staffmember.h"

// Constructor.
StaffMember::StaffMember(QString name, QDate date, ApptType type)
    : m_Name(name), m_BirthDate(date), m_ApptType(type)
{
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

// Functions for getting string from enum.
QString StaffMember::enumToString(ApptType type) const
{
    static const QMetaObject* metaObj = metaObject();
    int i = metaObj->indexOfEnumerator("ApptType");
    QMetaEnum metaEnum = metaObj->enumerator(i);

    return metaEnum.valueToKey(type);
}

QString StaffMember::getApptTypeString() const
{
    return StaffMember::enumToString(m_ApptType);
}

// Function to return staff member data as one string.
QString StaffMember::toString() const
{
    return QString("Name: %1, Birth Date: %2, Appointment Type: %3\n")
                .arg(m_Name)
                .arg(m_BirthDate.toString("yyyy-MM-dd"))
                .arg(enumToString(m_ApptType));
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

// Overloaded setter which accepts a string for enum data member.
void StaffMember::setApptType(QString type)
{
    // Use the metaObject to get enum property.
    static const QMetaObject* metaObj = metaObject();
    int i = metaObj->indexOfProperty("apptType");
    QMetaProperty metaProp = metaObj->property(i);
    QMetaEnum metaEnum = metaProp.enumerator();

    // Convert QString to char*.
    char* key = type.toLatin1().data();

    // Get enum value from key and set the data member.
    StaffMember::ApptType apptType = static_cast<StaffMember::ApptType>(metaEnum.keyToValue(key));
    m_ApptType = apptType;
}
