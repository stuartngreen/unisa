// Display soccer players who received more cards than goals scored by them.
#include <iostream>
#include <string>
using namespace std;

const int NR_PLAYERS = 12;

// Capture the goals and cards amounts
void inputInformation(const string namesP[], int goalsP[], int cardsP[])
{
    cout << "Enter the number of goals followed by cards for:" << endl;

    for (int i = 0; i < NR_PLAYERS; i++)
    {
        cout << namesP[i] << ": ";
        cin >> goalsP[i] >> cardsP[i];
    }
}

// Compare goals to cards and record offending player names
void findPlayersWithMoreCardsThanGoals(const string namesP[], const int goalsP[],
                                       const int cardsP[], string namesMoreP[],
                                       int& playerCountP)
{
    for (int i = 0; i < NR_PLAYERS; i++)
    {
        if (cardsP[i] > goalsP[i])
        {
            namesMoreP[playerCountP] = namesP[i];
            playerCountP++;
        }
    }
}

// Display the names of players with more cards than goals
void displayInfo(const string namesMoreP[], int playerCountP)
{
    if (playerCountP > 0)
    {
        cout << "\nThe players with more cards than goals are:" << endl;
        for (int i = 0; i < playerCountP; i++)
            cout << namesMoreP[i] << endl;
        cout << "\n";
    }
    else
        cout << "\nNo players had more cards than goals.\n";
}

int main()
{
    // Declare required arrays and variables
    string names[] = { "Tiny Nakedi", "Cecil Mametsa", "Chris Rooney", "Mario Thomas",
                       "Frank Ntini", "Charlie Ashley", "Morio Zondo", "Khabo Mosimane",
                       "Pitso Hack", "Lloyd Mokoena", "Rick Smith", "Kabelo Ramago" };
    int goals[NR_PLAYERS];
    int cards[NR_PLAYERS];
    string namesMore[NR_PLAYERS];
    int playerCount = 0;

    inputInformation(names, goals, cards);
    findPlayersWithMoreCardsThanGoals(names, goals, cards, namesMore, playerCount);
    displayInfo(namesMore, playerCount);

    return 0;
}
