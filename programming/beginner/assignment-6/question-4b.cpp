// Guess the number
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Capture the guess
int getGuess(int & valueGuessed)
{
    cin >> valueGuessed;
}

// Test the value of the guess
bool isCorrect(int valueGuessedP, int randomNumberP)
{
    if (valueGuessedP == randomNumberP)
        return true;
    else if (valueGuessedP < randomNumberP)
    {
        cout << "Too low. Try again." << endl << "? ";
        return false;
    }
    else
    {
        cout << "Too high. Try again." << endl << "? ";
        return false;
    }
}

// Evaluate the number of guesses
int analyzeCount(int noOfGuessesP)
{
    cout << "You have made " << noOfGuessesP << " guesses!" << endl;
    if (noOfGuessesP <= 10)
        cout << "Either you know the secret or you got lucky!" << endl;
    else if (noOfGuessesP == 10)
        cout << "Ahah! You know the secret!" << endl;
    else
        cout << "You should be able to do better!" << endl;
}

int main()
{
    int randomNumber, valueGuessed, noOfGuesses = 0;
    char playAgain = 'y';

    do
    {
        // Generate a random number between 1 and 1000
        srand(time(0));
        randomNumber = 1 + rand() % 1000;

        // Display message
        cout << "I have a number between 1 and 1000." << endl;
        cout << "Can you guess my number?" << endl;
        cout << "\nPlease type your first guess." << endl << "? ";

        // Keep testing the guess until it is correct
        do
        {
            getGuess(valueGuessed);
            noOfGuesses++;

        } while (isCorrect(valueGuessed, randomNumber) == false);

        // Display output message when guess is correct
        cout << "Excellent! You guessed the number!" << endl;
        analyzeCount(noOfGuesses);

        cout << "Would you like to play again? (y or n)" << endl;
        cin >> playAgain;

    } while (playAgain == 'y');

    return 0;
}
