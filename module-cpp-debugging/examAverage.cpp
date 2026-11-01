#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int exam1, exam2, exam3;
    double average;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter Exam 1 score: ";
    cin >> exam1;

    cout << "Enter Exam 2 score: ";
    cin >> exam2;

    cout << "Enter Exam 3 score: ";
    cin >> exam3;

    average = (exam1 + exam2 + exam3) / 3.0;

    cout << "Student: " << name << endl;
    cout << "Average: " << average << endl;

    if (average >= 70)
    {
        cout << "You passed!" << endl;
    }
    else
    {
        cout << "You did not pass." << endl;
    }

    return 0;
}
