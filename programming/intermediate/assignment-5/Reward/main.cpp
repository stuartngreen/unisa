// Tutorial letter program for Assignment 2 Question 2.
#include <iostream>
#include <iomanip>
#include "Reward.h"
using namespace std;

int main()
{
    RewardCard ACard;
    RewardCard MyCard("Hansie", "111111", "OurStore", 100);
    cout << "This is ACard: " << ACard << endl;
    cout << "This is MyCard: " << MyCard << endl;

    // Setting ACard to a new value.
    ACard.setName("Hansie");
    ACard.setId("111111");
    ACard.setStore("OurStore");
    ACard.setPoints(0);
    if (MyCard == ACard)
        cout << "These cards are the same." << endl;
    else
        cout << "These cards are not the same." << endl;

    // Giving Hansie 200 bonus points.
    ++MyCard;
    ++MyCard;
    cout << "\nAfter giving Hansie 200 bonus points:" << endl;
    cout << MyCard << endl;

    // Hansie has bought goods which earned 350 points.
    cout << "Enter details for purchase of goods with points value of 350 points:" << endl;
    cin >> ACard;
    MyCard = MyCard + ACard;
    cout << "Result after earning 350 points:" << endl << MyCard << endl;

    // Hansie returned goods which has earned 100 points - this must now be deducted.
    cout << "Enter details for return of goods with points value of 100 points:" << endl;
    cin >> ACard;
    MyCard = MyCard - ACard;
    cout << "Result after deducting 100 points:" << endl << MyCard << endl;

    return 0;
}
