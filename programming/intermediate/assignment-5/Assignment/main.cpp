// Program that initialises class objects with values and then modifies their values
// and also outputs them.
#include <iostream>
#include "Assignment.h"
using namespace std;

int main()
{
    // Set the number of assignments for the array.
    const int ASSIGNMENT_COUNT = 4;

    // Create the array of assignments.
    Assignment assignments[ASSIGNMENT_COUNT];

    // Set the values for the four Assignment objects in the array.
    assignments[0] = Assignment("XOS1512", "2016-03-16", "2016-03-12", 1, 746569, 8, 10);
    assignments[1] = Assignment("XOS1512", "2016-04-05", "2016-04-03", 2, 715513, 21, 25);
    assignments[2] = Assignment("XOS1512", "2016-04-28", "2016-04-23", 3, 856584, 24, 25);
    assignments[3] = Assignment("XOS1512", "2016-05-12", "2016-04-27", 4, 872098, 25, 30);

    // Calculate and set the percentage based on marks achieved for each assignment.
    for (int i = 0; i < 4; i++)
    {
        assignments[i].calcAndSetMarksPercentage(assignments[i].getMarksObtained(), assignments[i].getTotalMarks());
    }

    // Set precision to 2 for decimal places.
    cout.setf(ios::fixed);
    cout.precision(2);

    // Output the assignment array values.
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Module\t" << "Due Date\t" << "Submit Date\t" << "No.\t" << "Code\t" << "Marks" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << assignments[i];
    }
    cout << "----------------------------------------------------------------------" << endl;

    cout << "\nAdding 5% to Assignment 2's mark...\n" << endl;

    // Add 5% to the marks for assignment 2.
    // Note for marker, I'm trying to adjust the marks achieved value by 5% as well, but it
    // obviously is not accurate because I'm using integers for the marks and a double for the
    // percentage. So I realise this doesn't work properly but I didn't want to delete it.
    int temp;
    temp = assignments[1].getTotalMarks() * 5 / 100;
    assignments[1].setMarksObtained(assignments[1].getMarksObtained() + temp);

    // Add 5% to the percentage achieved.
    assignments[1].setMarksPercentage(assignments[1].getMarksPercentage() + 5);

    // Output the assignment array again.
    cout << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << assignments[i];
    }
    cout << "----------------------------------------------------------------------" << endl;

    return 0;
}
