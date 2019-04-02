// Driver program for class "Package".
#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
using namespace std;

const double extra_fee = 5;

int main()
{
    // Instantiate object of base class "Package".
    Package the_package(12.75, 1.25, "Charles Somerset", "Anne Barnard");

    // Output the names of the sender and the receiver.
    cout << "Sender: " << the_package.get_sender() << endl;
    cout << "Recipient: " << the_package.get_recipient() << endl;

    // Determine and output the cost of the package.
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Cost of package: R" << the_package.calculate_cost() << endl;

    // Instantiate object of derived class "TwoDayPackage".
    TwoDayPackage the_two_day_package(12.75, 1.25, "Charles Somerset", "Anne Barnard");

    // Output the names of the sender and the receiver.
    cout << "Sender: " << the_two_day_package.get_sender() << endl;
    cout << "Recipient: " << the_two_day_package.get_recipient() << endl;

    // Determine and output the cost of the package.
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Cost of package: R" << the_two_day_package.calculate_cost() << endl;

    return 0;
}
