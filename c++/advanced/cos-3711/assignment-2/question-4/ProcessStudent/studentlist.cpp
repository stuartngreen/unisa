// Implementation file for class 'StudentList'.

#include "studentlist.h"

// Declaration of static StudentList.
StudentList* StudentList::m_StudentList = NULL;

// Constructor.
StudentList::StudentList()
{
}

// Function to return the single StudentList instance.
StudentList* StudentList::instance()
{
    if (m_StudentList == NULL)
        m_StudentList = new StudentList;

    return m_StudentList;
}

// Function to append a student to the list.
void StudentList::addStudent(Student* student)
{
    QString studentNum = student->getNumber();
    int index = getStudentIndex(studentNum);

    // Check if the student already exists in the list...
    if (index != -1)
    {
        // Get the modules from the student object.
        QMap<QString, double> modules = student->getModules();

        // Insert them into the existing student in the list.
        foreach(QString moduleCode, modules.keys())
            this->at(index)->addModule(moduleCode, modules.value(moduleCode));

        delete student;
    }
    // ...else, add the new student.
    else
        this->append(student);

}

// Function to return the whole list.
QList<Student*> StudentList::getStudentList() const
{
    return *this;
}

// Function to get the matching student object's index in the list.
int StudentList::getStudentIndex(QString num) const
{
    QString currentNum;
    for (int i = 0; i < this->count(); i++)
    {
        // Get the student number of the current Student object.
        currentNum = this->at(i)->getNumber();

        // If there is a match, return its index.
        if (currentNum == num)
            return i;
    }
    return -1;
}

// Function to return the student object matching the index.
Student* StudentList::getStudent(int index) const
{
    if (index < this->count())
        return this->at(index);
    return NULL;
}

// Function to return the list size.
int StudentList::getListSize() const
{
    return this->size();
}
