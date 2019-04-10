// Interface file for class 'StaffMember' which represents information about a staff member
// comprised of name, birth date and appointment type (Permanent, PartTime, Contract).
// There is a:
//  - Q_PROPERTYs for use with finding QMetaObject information,
//  - enum ApptType listing the possible values for appointment type enum,
//  - constructor which accepts values for the data members,
//  - private getters to get the values of the data members via reflective programming,
//  - private setters to set the values of the data members via reflective programming.

#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QMetaEnum>
#include <QDebug>

class StaffMember : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Name READ getName WRITE setName)
    Q_PROPERTY(QDate Birth_Date READ getBirthDate WRITE setBirthDate)
    Q_PROPERTY(ApptType Appointment_Type READ getApptType WRITE setApptType)

public:
    enum ApptType { NotSet = -1, Permanent, PartTime, Contract };
    Q_ENUMS(ApptType)

    // Constructor
    explicit StaffMember(QString name, QDate date, ApptType type);

private:
    // Getters
    QString getName() const;
    QDate getBirthDate() const;
    ApptType getApptType() const;

    // Setters
    void setName(QString name);
    void setBirthDate(QDate date);
    void setApptType(QString type);
    void setApptType(ApptType type);

    // Data members
    QString m_Name;
    QDate m_BirthDate;
    ApptType m_ApptType;
};

Q_DECLARE_METATYPE(StaffMember::ApptType)

#endif // STAFFMEMBER_H
