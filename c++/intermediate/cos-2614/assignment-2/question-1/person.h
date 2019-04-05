// Interface file for class 'Person' that represents a person making a booking, comprised of
// name, contact number, and email address. There is a:
//  - constructor which accepts values for the data members;
//  - toString() function which returns a neatly formatted string comprised of the data members.

#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
public:
    Person(QString n, QString c, QString e);
    QString toString() const;
private:
    QString m_Name;
    QString m_ContactNo;
    QString m_Email;
};

#endif // PERSON_H
