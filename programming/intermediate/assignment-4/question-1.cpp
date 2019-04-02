#include <iostream>
using namespace std;

// Class for university module information.
class Module
{
public:
    // Overloaded constructor that initialises private member variables to provided values.
    Module(string modName, string modCode, string modLecturer, int modNrStudents);

    // Default constructor that initialises private member string values to empty and nrStudents to 0.
    Module();

    // Mutators to set private member values.
    void setModuleName(string modName);
    void setModuleCode(string modCode);
    void setLecturer(string modLecturer);
    void setNrStudents(int modNrStudents);

    // Accessors to get private member values.
    string getModuleName();
    string getModuleCode();
    string getLecturer();
    int getNrStudents();

    // Function to output all the private member values.
    void output();

private:
    string moduleName;
    string moduleCode;
    string lecturer;
    int nrStudents;
};

int main ()
{
    // Instantiate new object of Module class using default constructor
    Module newModule;

    // Declare variables to hold user input
    string tempStr;
    int tempInt;

    // Get the required info from the user.
    cout << "Please enter the module name: ";
    getline(cin, tempStr);
    newModule.setModuleName(tempStr);

    cout << "Please enter the module code: ";
    getline(cin, tempStr);
    newModule.setModuleCode(tempStr);

    cout << "Please enter the module lecturer: ";
    getline(cin, tempStr);
    newModule.setLecturer(tempStr);

    cout << "Please enter the number of students: ";
    cin >> tempInt;
    newModule.setNrStudents(tempInt);

    // Output the entered info to the screen.
    newModule.output();

    // Extra example using the overloaded constructor:
    cout << "\nAn extra example instantiated using the overloaded constructor:" << endl;
    Module exampleModule("Stuart's Module", "STU001", "Stuart Green", 10);
    exampleModule.output();

    return 0;
}

Module::Module(string modName, string modCode, string modLecturer, int modNrStudents)
{
    // Overloaded constructor that accepts 4 values.
    moduleName = modName;
    moduleCode = modCode;
    lecturer = modLecturer;
    nrStudents = modNrStudents;
}

Module::Module() : moduleName(""), moduleCode(""), lecturer(""), nrStudents(0)
{
    // Default constructor to initialise values to empty and zero respectively.
}

// Mutators to set private member values.
void Module::setModuleName(string modName)
{
    moduleName = modName;
}

void Module::setModuleCode(string modCode)
{
    moduleCode = modCode;
}

void Module::setLecturer(string modLecturer)
{
    lecturer = modLecturer;
}

void Module::setNrStudents(int modNrStudents)
{
    nrStudents = modNrStudents;
}

// Accessors to get private member values.
string Module::getModuleName()
{
    return moduleName;
}

string Module::getModuleCode()
{
    return moduleCode;
}

string Module::getLecturer()
{
    return lecturer;
}

int Module::getNrStudents()
{
    return nrStudents;
}

// Function to output all the private member values.
void Module::output()
{
    // Output the values to the screen.
    cout << "\nModule name: " << getModuleName() << endl;
    cout << "Module code: " << getModuleCode() << endl;
    cout << "Lecturer: " << getLecturer() << endl;
    cout << "Number of students: " << getNrStudents() << endl;
}
