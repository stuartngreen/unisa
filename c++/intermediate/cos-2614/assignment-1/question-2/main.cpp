// Semester 1: Assignment 1 Question 2
// Program to implement Product and Vendor classes by creating and testing
// a Product object.
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include "product.h"
#include "vendor.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

void getProductDetails(QString &name, double &price);
void getVendorDetails(QString &name, QString &email);

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Declare some variables needed for the program.
    QString productName, vendorName, vendorEmail;
    double productPrice;

    // Get the product name and price from the user.
    getProductDetails(productName, productPrice);

    // Create new product object.
    Product myProduct(productName, productPrice);

    cout << endl;

    // Get the supplier details from the user.
    getVendorDetails(vendorName, vendorEmail);


    cout << "\n======== TESTING ========" << endl;

    // Testing the getManufacturerName() function.
    cout << "\nIf the supplier is also the manufacturer, the manufacturer is: " << flush;
    myProduct.setSupplier(vendorName, vendorEmail, true);
    cout << myProduct.getManufacturerName() << endl;

    cout << "If the supplier is not the manufacturer, the manufacturer is: " << flush;
    myProduct.setSupplier(vendorName, vendorEmail, false);
    cout << myProduct.getManufacturerName() << endl;

    // Testing the toString() function of the Product class.
    cout << "\nThe product details are as follows:" << endl;
    cout << myProduct.toString(false) << endl;

    cout << "\nThe product and supplier details are as follows:" << endl;
    cout << myProduct.toString(true) << endl;

    cout << endl;

    return EXIT_SUCCESS;
}

void getProductDetails(QString &name, double &price)
{
    cout << "----- Enter product details: -----" << endl;
    cout << "Name: " << flush;
    name = cin.readLine();
    cout << "Price: " << flush;
    cin >> price;
    cin.readLine();
}

void getVendorDetails(QString &name, QString &email)
{
    cout << "----- Enter supplier details: -----" << endl;
    cout << "Name: " << flush;
    name = cin.readLine();
    cout << "Email: " << flush;
    cin >> email;
    cin.readLine();
}




/*
// I was a bit confused by the question... here is some code I had where
// the user can input whether the vendor is also the manufacturer.
// However, to test the getManufacturerName() function I had to override
// the user's selection anyway.

bool isVendorManufacturer = false;
QChar answer;

do
{
    cout << "Is the vendor also the manufacturer? [y/n]: " << flush;
    cin >> answer;
    cin.readLine();

} while (answer.toLower() != 'n' && answer.toLower() != 'y');

if (answer == 'y')
    isVendorManufacturer = true;
*/
