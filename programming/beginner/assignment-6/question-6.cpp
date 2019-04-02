#include <iostream>
#include <string>
using namespace std;

//void determineFee(string customerP, float & amntDueP, float & costP, float & timeSpentP);
void determineFee(string customerP, float & amntDueP, float & costP, float timeSpentP)
{

}

int main()
{
    string customer = "Anna Elias";
    float amountDue;
    float timeSpent = 72.56;
    float cost = 1534.78;

    determineFee(customer, amountDue, cost, 200.53);

    return 0;
}

/*
void processData(string studentNrP, string nameP, int & markP, int & nrPassedP)
{
    if (markP == 48) || (markP == 49)
        markP = 50;
    if (markP == 74)
        markP = 75;
    if (markP >= 50)
        ++nrPassedP;
    cout << "Final mark for student" << studentNrP << string nameP << " is " << markP << endl;
}

void processData(string studentNrP, string nameP, int & markP, int & nrPassedP)
{
    cout << studentNrP << nameP << markP << nrPassedP;
}

int main()
{
    string name, studentNr;
    int mark;
    int nrPassed = 0;
    cin >> name >> studentNr >> mark;
    processData(name, studentNr, mark, 0);
    studentNr = "8954321";
    name = "Mr. John Smith";
    processData(name, studentNr, 74, nrPassed );
    processData("Ms. Beauty Sithole","4327834" , mark, nrPassed);
    return 0;
}
*/
