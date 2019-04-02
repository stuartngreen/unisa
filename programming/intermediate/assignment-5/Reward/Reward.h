// Interface file for class 'RewardCard' that represents a card on which
// members can earn points. There are two constructors, a default which
// initialises the strings name, id and store and integer points to default
// values, and another constructor where those values can be specified. There
// are friend functions to override operators ==, ++, +, -, << and >>.
#ifndef REWARD_H
#define REWARD_H

#include <iostream>
#include <cassert>
using namespace std;

class RewardCard
{
public:
    // Default constructor that initialises private member variable values.
    RewardCard();

    // Overloaded constructor that accepts values for the three strings, and
    // sets the points value to zero.
    RewardCard(string theName, string theId, string theStore,
        int thePoints = 0);

    // Destructor
    ~RewardCard();

    // Overloading operator == to test equality of RewardCard objects.
    friend bool operator ==(const RewardCard& card1, const RewardCard& card2);

    // Overloading operator ++ to increment 100 bonus points to RewardCard.
    friend RewardCard operator ++(RewardCard& card);

    // Overloading operator + to add points of RewardsCard ojbects if they
    // are the same card.
    friend RewardCard operator +(RewardCard& card1, RewardCard& card2);

    // Overloading operator - to subtract points of RewardsCard ojbects if
    // they are the same card.
    friend RewardCard operator -(RewardCard& card1, RewardCard& card2);

    // Overloading operator << to ouput values of object type RewardCard.
    friend ostream& operator <<(ostream& outs, const RewardCard& RC);

    // Overloading operator >> to input values of object type RewardCard.
    friend istream& operator >>(istream& ins, RewardCard& RC);

    // Mutators to set private member values.
    void setName(string theName);
    void setId(string theId);
    void setStore(string theStore);
    void setPoints(int thePoints);

    // Accessors to get private member values.
    string getName();
    string getId();
    string getStore();
    int getPoints();

private:
    string name;
    string id;
    string store;
    int points;
};

#endif
