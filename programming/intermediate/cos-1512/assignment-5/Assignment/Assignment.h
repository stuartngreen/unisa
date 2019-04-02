// Interface file for class 'Assignment' that represents a module assignment's
// pertinant information and results achieved. There are two constructors: a
// default one that sets up default values, and an overloaded one that can accept
// values for all private member variables besides the percentage obtained, which
// is calculated later. You can send the marks obtained and total marks to the
// calcAndSetMarksPercentage function to set that value. There are also accessors
// and mutators for all the values. The outsream operator is also overloaded to
// output the values of an Assignment object.
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
using namespace std;

class Assignment
{
public:
    // The constructors: default and overloaded.
    Assignment();
    Assignment(string theModule, string theDueDate, string theSubmitDate, int theAssignmentNumber,
        int theAssignmentCode, int theMarksObtained, int theTotalMarks);

    // Accessors to get the values of the private member variables.
    string getModule();
    string getDueDate();
    string getSubmitDate();
    int getAssignmentNumber();
    int getAssignmentCode();
    int getMarksObtained();
    int getTotalMarks();
    double getMarksPercentage();

    // Mutators to set the values of the private member variables.
    void setModule(string theModule);
    void setDueDate(string theDueDate);
    void setSubmitDate(string theSubmitDate);
    void setAssignmentNumber(int theAssignmentNumber);
    void setAssignmentCode(int theAssignmentCode);
    void setMarksObtained(int theMarksObtained);
    void setTotalMarks(int theTotalMarks);
    void setMarksPercentage(double theMarksPercentage);

    // Calculates and sets the percentage obtained from the marks obtained and total marks.
    void calcAndSetMarksPercentage(double mark1, double mark2);

    // Overloaded outstream operator to output the values of the member variables.
    friend ostream& operator <<(ostream& outs, const Assignment& theAssignment);

private:
    // The private member variables.
    string module;
    string dueDate;
    string submitDate;
    int assignmentNumber;
    int assignmentCode;
    int marksObtained;
    int totalMarks;
    double marksPercentage;
};

#endif
