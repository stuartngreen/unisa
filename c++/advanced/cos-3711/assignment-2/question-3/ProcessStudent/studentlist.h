// Interface file for singleton class 'StudentList' which inherits from QList, and keeps
// a single list of Student objects. There is a:
// - private constructor,
// - instance() function to return the single StudentList instance,
// - addStudent() function to append a student to the list,
// - getStudentList() function to return the whole list,
// - getStudentIndex() function to get the matching student object's index in the list,
// - getStudent() function to return the student object matching the index,
// - getListSize() function to return the list size.

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QList>
#include "student.h"

class StudentList : public QList<Student*>
{
public:
    static StudentList* instance();
    void addStudent(Student* student);
    QList<Student*> getStudentList() const;
    int getStudentIndex(QString num) const;
    Student* getStudent(int index) const;
    int getListSize() const;

private:
    StudentList();
    static StudentList* m_StudentList;
};

#endif // STUDENTLIST_H
