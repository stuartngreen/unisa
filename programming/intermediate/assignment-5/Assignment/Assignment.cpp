// Implementation file for class 'Assignment' in Assignment.h header file.
// Contains all the definitions for the declared functions in the class.
#include "Assignment.h"

// Default constructor that initialises private member variables to some default values.
Assignment::Assignment() : module(""), dueDate(""), submitDate(""), assignmentNumber(0),
    assignmentCode(000000), marksObtained(0), totalMarks(0), marksPercentage(0)
{
    //
}

// Overloaded constructor that accepts values for all variables except the percentage marks,
// which is calculated later from the marks obtained and total marks values.
Assignment::Assignment(string theModule, string theDueDate, string theSubmitDate,
    int theAssignmentNumber, int theAssignmentCode, int theMarksObtained, int theTotalMarks)
{
    module = theModule;
    dueDate = theDueDate;
    submitDate = theSubmitDate;
    assignmentNumber = theAssignmentNumber;
    assignmentCode = theAssignmentCode;
    marksObtained = theMarksObtained;
    totalMarks = theTotalMarks;
    marksPercentage = 0;
}

// Mutator functions to set the values of member variables.
void Assignment::setModule(string theModule)
{
    module = theModule;
}

void Assignment::setDueDate(string theDueDate)
{
    dueDate = theDueDate;
}

void Assignment::setSubmitDate(string theSubmitDate)
{
    submitDate = theSubmitDate;
}

void Assignment::setAssignmentNumber(int theAssignmentNumber)
{
    assignmentNumber = theAssignmentNumber;
}

void Assignment::setAssignmentCode(int theAssignmentCode)
{
    assignmentCode = theAssignmentCode;
}

void Assignment::setMarksObtained(int theMarksObtained)
{
    marksObtained = theMarksObtained;
}

void Assignment::setTotalMarks(int theTotalMarks)
{
    totalMarks = theTotalMarks;
}

void Assignment::setMarksPercentage(double theMarksPercentage)
{
    marksPercentage = theMarksPercentage;
}

// Calculates and sets the percentage obtained from the marks obtained and total marks.
void Assignment::calcAndSetMarksPercentage(double mark1, double mark2)
{
    marksPercentage = mark1 / mark2 * 100;
}

// Overloaded outstream operator to output the values of the member variables.
ostream& operator <<(ostream& outs, const Assignment& theAssignment)
{
    outs << theAssignment.module << "\t" << theAssignment.dueDate << "\t"
        << theAssignment.submitDate << "\t" << theAssignment.assignmentNumber << "\t"
        << theAssignment.assignmentCode << "\t" << theAssignment.marksObtained << "/"
        << theAssignment.totalMarks << "\t" << theAssignment.marksPercentage << "%" << endl;
    return outs;
}

// Accessor functions to get the values from the private member variables.
string Assignment::getModule()
{
    return module;
}

string Assignment::getDueDate()
{
    return dueDate;
}

string Assignment::getSubmitDate()
{
    return submitDate;
}

int Assignment::getAssignmentNumber()
{
    return assignmentNumber;
}

int Assignment::getAssignmentCode()
{
    return assignmentCode;
}

int Assignment::getMarksObtained()
{
    return marksObtained;
}

int Assignment::getTotalMarks()
{
    return totalMarks;
}

double Assignment::getMarksPercentage()
{
    return marksPercentage;
}
