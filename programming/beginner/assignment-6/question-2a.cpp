#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int totNrVultureEggs, totNrEagleEggs, totNrOwlEggs, nrEggs,
        nrVultureEggs, nrEagleEggs, nrOwlEggs, nrBirdWatchers;
    char bird;

    // initialize grand totals for number of eggs for each type of bird
    totNrVultureEggs = 0;
    totNrEagleEggs = 0;
    totNrOwlEggs = 0;

    cout << "How many bird watchers took part in the study? ";
    cin >> nrBirdWatchers;

    // loop over number of bird watchers
    for (int i = 0; i < nrBirdWatchers; i++)
    {
        // initialize totals for number of eggs for each type of bird
        // this bird watcher saw
        nrVultureEggs = 0;
        nrEagleEggs = 0;
        nrOwlEggs = 0;

        cout << "\nEnter data for bird watcher " << i + 1 << ":" << endl;

        //loop over bird watchers
        cout << "\nEnter the bird type and number of eggs in sequence, e.g. E1 O1 etc." << endl;
        do
        {
            cin >> bird >> nrEggs;

            // capture number of bird eggs
            switch (bird)
            {
                case 'v':
                case 'V':
                    nrVultureEggs += nrEggs;
                    break;
                case 'e':
                case 'E':
                    nrEagleEggs += nrEggs;
                    break;
                case 'o':
                case 'O':
                    nrOwlEggs += nrEggs;
                    break;
                default:
                    cout << "";
            }

        } while (bird != 'x' && bird != 'X');

        cout << "Bird watcher " << i + 1 << " saw " << nrVultureEggs;
        cout << " vulture eggs, " << nrEagleEggs << " eagle eggs and ";
        cout << nrOwlEggs << " owl eggs " << endl;

        // increment grand totals for eggs
        totNrVultureEggs += nrVultureEggs;
        totNrEagleEggs += nrEagleEggs;
        totNrOwlEggs += nrOwlEggs;
    }

    // display results
    cout << "\nTotal number of vulture eggs: " << totNrVultureEggs;
    cout << "\nTotal number of eagle eggs: " << totNrEagleEggs;
    cout << "\nTotal number of owl eggs: " << totNrOwlEggs;

    return 0;
}
