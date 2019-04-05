// Calculate and display average hours of study for each module
#include <iostream>
using namespace std;

const int NR_FRIENDS = 4;
const int NR_MODULES = 3;

// Capture the hours per module per friend
void inputHours(const string friendsP[], const string modulesP[], int hoursStudiedP[][NR_MODULES])
{
    for (int i = 0; i < NR_FRIENDS; i++)
    {
        cout << "Enter the hours per module for " << friendsP[i] << ":" << endl;
        for (int j = 0; j < NR_MODULES; j++)
        {
            cout << modulesP[j] << ": ";
            cin >> hoursStudiedP[i][j];
        }
    }
}

// Calculate and return the least amount of hours studied by a student
int hoursLeast(const int hoursStudiedP[][NR_MODULES])
{
    int total;
    int least = -1;

    for (int i = 0; i < NR_FRIENDS; i++)
    {
        total = 0;

        for (int j = 0; j < NR_MODULES; j++)
            total += hoursStudiedP[i][j];

        if (least == -1)
            least = total;
        else if (least != -1 && total < least)
            least = total;
    }

    return least;
}

// Display average hours spent on each module
void displayAverages(const string modulesP[], const int hoursStudiedP[][NR_MODULES])
{
    float average;

    for (int j = 0; j < NR_MODULES; j++)
    {
        average = 0;

        for (int i = 0; i < NR_FRIENDS; i++)
            average += hoursStudiedP[i][j];

        average = average / NR_FRIENDS;
        cout << "The average hours spent on module " << modulesP[j] << " was " << average << " hours." << endl;
    }
}

int main()
{
    string friends[] = { "Aggie", "Bruce", "Cecil", "Danita" };
    string modules[] = { "ABC111", "DEF222", "GHI333" };
    int hoursStudied[NR_FRIENDS][NR_MODULES];

    // Get the hours spent on each module by each student
    inputHours(friends, modules, hoursStudied);

    // Display least amount of hours studied
    cout << "The least amount of hours studied by a student was " << hoursLeast(hoursStudied) << "." << endl;

    // Display average hours studied per module
    displayAverages(modules, hoursStudied);

    return 0;
}
