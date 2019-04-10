// Interface file for class 'Student' which represents a Student object consisting of a
// student number and module list with marks obtained for each. There is a:
// - constructor and destructor,
// - average() function to return the average of all marks,
// - graduate() function to check if a student has passed,
// - setter and getter for student number member,
// - addModule() function to add a module and mark to the QMap member,
// - getModules() function to return the QMap,
// - toString() function to return all the contents of a Student object as a string.

#ifndef STUDENT_H
#define STUDENT_H

#include <QDebug>
#include <QChar>
#include <QString>
#include <QStringList>
#include <QMap>

class Student
{
public:
    Student();
    ~Student();

    void setNumber(QString num);
    QString getNumber() const;
    void addModule(QString module, double mark);
    QMap<QString, double> getModules() const;

    double average();
    bool graduate();
    QString toString() const;

private:
    QString m_StudentNum;
    QMap<QString, double> m_ModuleMarks;
};

#endif // STUDENT_H
