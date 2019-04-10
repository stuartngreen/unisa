// Interface file for class 'StaffMember' which represents information about a staff member
// comprised of name, birth date and appointment type (Permanent, PartTime, Contract).
// There is a :
//  - enum ApptType listing the possible values for appointment type enum,
//  - constructor which accepts values for the data members,
//  - getters to get the values of the data members,
//  - setters to set the values of the data members,
//  - functions enumToString and getApptTypeString to get strings from enum,
//  - toString function to return staff member data as one string.

#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QMetaEnum>

class StaffMember : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ApptType apptType READ getApptType WRITE setApptType)

public:
    enum ApptType { NotSet = -1, Permanent, PartTime, Contract };
    Q_ENUMS(ApptType)

    // Constructor.
    explicit StaffMember(QString name, QDate date, ApptType type);

    // Getters.
    QString getName() const;
    QDate getBirthDate() const;
    ApptType getApptType() const;

    // For getting strings from enum.
    QString enumToString(ApptType type) const;
    QString getApptTypeString() const;

    // Returns staff member data as one string.
    QString toString() const;

    // Setters.
    void setName(QString name);
    void setBirthDate(QDate date);
    void setApptType(QString type);
    void setApptType(ApptType type);

private:
    QString m_Name;
    QDate m_BirthDate;
    ApptType m_ApptType;
};

#endif // STAFFMEMBER_H
