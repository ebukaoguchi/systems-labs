#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    int numStores, numDays;

    cout << "How many Stores will be process: " << endl;
    cin >> numStores;

    cout << "How many Days of sales will be recorded: " << endl;
    cin >> numDays;

        ofstream outfile;
        outfile.open("sales_report.txt");

        if (!outfile){
            cout << "Invalid File!" << endl;
            return 1;
        }
    for (int store = 1; store <= numStores; store++){
        int total = 0;
        for (int day = 1; day <= numDays; day++){
            int sales;
            cout << "Store: " << store << " Day: " << day << "\t" << "Sales = ";
            cin >> sales;
            total += sales;
        }
        // Hold on
        outfile << "Stores: " << store << "\t" << "Total $" << total;

        if (total >= 500){
            outfile << " - Good" << endl;
        }
        else
        {
            outfile << " - Needs Improvement" << endl;
        }

    }
    outfile.close();

    ifstream infile;
    infile.open("sales_report.txt");

    if (!infile){
        cout << "Cant Read File!" << endl;
        return 1;
    }
    string line;
    cout << "\n %%%%%Weekly Sales Report\n" << endl;

    while (getline(infile, line)){
        cout << line << endl;
    }

    infile.close();

    return 0;
}