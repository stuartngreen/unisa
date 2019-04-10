// Implementation file for class 'Student'.

#include "student.h"

// Constructor.
Student::Student()
{
}

// Destructor.
Student::~Student()
{
}

// Setter for m_StudentNum.
void Student::setNumber(QString num)
{
    m_StudentNum = num;
}

// Getter for m_StudentNum.
QString Student::getNumber() const
{
    return m_StudentNum;
}

// Function to add a module and mark to the QMap member.
void Student::addModule(QString module, double mark)
{
    m_ModuleMarks.insert(module, mark);
}

// Function to return the QMap member.
QMap<QString, double> Student::getModules() const
{
    return m_ModuleMarks;
}

// Function to return the average of all marks.
double Student::average()
{
    double marksSum = 0;
    int noOfModules = m_ModuleMarks.count();

    // Get a total of all the marks for all modules.
    foreach(double mark, m_ModuleMarks.values())
        marksSum += mark;

    return marksSum / noOfModules;
}

// Function to check if a student has passed.
bool Student::graduate()
{
    int passedModuleCount = 0, firstYearModuleCount = 0, thirdYearModuleCount = 0;

    // Evaluate each module in the student object.
    foreach(QString moduleCode, m_ModuleMarks.keys())
    {
        // Get the module mark and year.
        double mark = m_ModuleMarks.value(moduleCode);
        QChar year = moduleCode[3];

        // If the student passed, count the module.
        if (mark >= 50)
        {
            passedModuleCount++;

            if (year == '1')
                firstYearModuleCount++;
            if (year == '3')
                thirdYearModuleCount++;
        }
    }

    if (passedModuleCount >= 5 && firstYearModuleCount <= 2 && thirdYearModuleCount >= 1)
        return true;

    return false;
}

// Function to return all the contents of a Student object as a string.
QString Student::toString() const
{
    QString studentInfo;
    studentInfo.append("Student number: " + m_StudentNum + "\n");

    foreach(QString moduleCode, m_ModuleMarks.keys())
    {
        studentInfo.append(QString("Module: %1  Mark: %2\n")
           .arg(moduleCode)
           .arg(m_ModuleMarks.value(moduleCode))
        );
    }

    return studentInfo;
}
