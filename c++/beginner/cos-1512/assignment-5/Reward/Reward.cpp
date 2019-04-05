// Implementation file for class 'RewardCard' in Reward.h header file.
// Contains all the definitions for the declared functions in the class.
#include "Reward.h"

// Default constructor that initialises private member variable values.
RewardCard::RewardCard() : name(""), id("000000"), store(""), points(0)
{
    //
}

// Overloaded constructor that accepts values for the three strings, and sets
// the points value to zero.
RewardCard::RewardCard(string theName, string theId, string theStore, int thePoints)
{
    name = theName;
    id = theId;
    store = theStore;
    points = thePoints;
}

// Destructor
RewardCard::~RewardCard()
{
    //
}

// Overloading operator == to test equality of RewardCard objects.
bool operator ==(const RewardCard& card1, const RewardCard& card2)
{
    if ((card1.name == card2.name) && (card1.id == card2.id)
        && (card1.store == card2.store))
        return true;
    else
        return false;
}

// Overloading operator ++ to increment 100 bonus points to RewardCard.
RewardCard operator ++(RewardCard& card)
{
    card.points += 100;
    return card;
}

// Overloading operator + to add points of RewardsCard ojbects if they are
// the card.
RewardCard operator +(RewardCard& card1, RewardCard& card2)
{
    assert(card1 == card2);
    card1.points += card2.points;
    return card1;
}

// Overloading operator - to subtract points of RewardsCard ojbects if they
// are the same card.
RewardCard operator -(RewardCard& card1, RewardCard& card2)
{
    assert(card1 == card2);
    card1.points -= card2.points;
    return card1;
}

// Overloading operator << to ouput values of object type RewardCard.
ostream& operator <<(ostream& outs, const RewardCard& RC)
{
    outs << "\n============================================================" << endl;
    outs << "Name:\t" << RC.name << endl;
    outs << "ID:\t" << RC.id << endl;
    outs << "Store:\t" << RC.store << endl;
    outs << "Points:\t" << RC.points << endl;

    if (RC.points > 500)
    {
        double amount = RC.points;
        amount = amount * 0.01;
        outs.setf(ios::fixed);
        outs.precision(2);
        outs << "Congratulations, you have enough points for a R" << amount << " voucher." << endl;
    }
    else
        outs << "Sorry, this is not enough points yet for a voucher! Keep on buying." << endl;

    outs << "============================================================" << endl;
    return outs;
}

// Overloading operator >> to input values of object type RewardCard.
istream& operator >>(istream& ins, RewardCard& RC)
{
    ins >> RC.name >> RC.id >> RC.store >> RC.points;
}

// Mutators to set values of private member variables.
void RewardCard::setName(string theName)
{
    name = theName;
}

void RewardCard::setId(string theId)
{
    id = theId;
}

void RewardCard::setStore(string theStore)
{
    store = theStore;
}

void RewardCard::setPoints(int thePoints)
{
    points = thePoints;
}

// Accessors to get value of private member variables.
string RewardCard::getName()
{
    return name;
}

string RewardCard::getId()
{
    return id;
}

string RewardCard::getStore()
{
    return store;
}

int RewardCard::getPoints()
{
    return points;
}
