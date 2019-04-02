// FloraServices Garden Services information
#include <iostream>
using namespace std;

const int NR_OF_GARDENS = 12;

// Struct for information about each garden
struct GardenInfo
{
    string clientAddress;
    string weekDay;
    int noOfWorkers;
    char hasPool;
};

// Capture the information for each garden
void inputInformation(GardenInfo gardensP[])
{
    for (int i = 0; i < NR_OF_GARDENS; i++)
    {
        // Prompt user for each information type
        cout << "\nEnter the details for client no. " << i + 1 << ":" << endl;

        cout << "> Address: ";
        getline(cin, gardensP[i].clientAddress, '\n');

        cout << "> Service week day: ";
        cin >> gardensP[i].weekDay;

        cout << "> No of workers required: ";
        cin >> gardensP[i].noOfWorkers;

        do
        {
            cout << "> Does the garden have a pool? (Y/N): ";
            cin >> gardensP[i].hasPool;

        } while (gardensP[i].hasPool != 'Y' && gardensP[i].hasPool != 'y'
                 && gardensP[i].hasPool != 'N' && gardensP[i].hasPool != 'n');

        cin.get();
    }
}

// Display some particular information (see cout statements below)
void displaySomeInformation(const GardenInfo gardensP[])
{
    cout << "\nThe addresses of all gardens serviced on Tuesdays are:" << endl;
    for (int i = 0; i < NR_OF_GARDENS; i++)
    {
        if (gardensP[i].weekDay == "Tuesday")
            cout << "> " << gardensP[i].clientAddress << endl;
    }

    cout << "\nThe service days and workers required for gardens with pools on Long St. are:" << endl;
    for (int i = 0; i < NR_OF_GARDENS; i++)
    {
        if ((gardensP[i].hasPool == 'Y' || gardensP[i].hasPool == 'y') && (gardensP[i].clientAddress.find("Long Street") != -1))
            cout << "> " << gardensP[i].weekDay << '\t' << gardensP[i].noOfWorkers << endl;
    }

    cout << "\nThe addresses of all gardens requiring more than 4 workers are:" << endl;
    for (int i = 0; i < NR_OF_GARDENS; i++)
    {
        if (gardensP[i].noOfWorkers > 4)
            cout << "> " << gardensP[i].clientAddress << endl;
    }
}

int main ()
{
    GardenInfo gardens[NR_OF_GARDENS];

    inputInformation(gardens);

    cout << "\n========================================" << endl;

    displaySomeInformation(gardens);

    return 0;
}
