// Compute and display the average of test results from experiments
#include <iostream>
using namespace std;

int main()
{
    // Declare required variables
    int noOfExperiments, noOfResults;
    float experimentResult, experimentResultsTotal, experimentAverage;

    // Capture number of experiments performed
    cout << "How many experiments were performed? ";
    cin >> noOfExperiments;

    // Capture results for each experiment
    for (int i = 1; i <= noOfExperiments; i++)
    {
        cout << "\n-------------" << endl;
        cout << "Experiment " << i << ":" << endl;
        cout << "-------------" << endl;

        // Capture number of results obtained
        cout << "\nHow many results were obtained? ";
        cin >> noOfResults;

        // Initialise/reset variables to zero
        experimentResult = 0,
        experimentResultsTotal = 0,
        experimentAverage = 0;

        // Capture each experiment result
        cout << "Enter the results: ";
        for (int j = 1; j <= noOfResults; j++)
        {
            cin >> experimentResult;
            experimentResultsTotal += experimentResult;
        }

        // Calculate and display average
        cout.setf(ios::fixed);
        cout.precision(2);
        experimentAverage = experimentResultsTotal / noOfResults;
        cout << "The average result for experiment " << i << " is " << experimentAverage << "." << endl;
    }

    return 0;
}
