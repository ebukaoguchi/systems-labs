#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

int main()
{
    int num1, num2, num3;
    int sum;
    double average;
    int choice;

    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;

    sum = num1 + num2 + num3;
    average = static_cast<double>(sum) / 3;

    cout << fixed << setprecision(2);
    cout << "Average: " << average << endl;
    cout << "Sum: " << sum << endl;

    cout << endl;
    cout << "Choose how to display the sum:" << endl;
    cout << "1. Binary" << endl;
    cout << "2. Octal" << endl;
    cout << "3. Hexadecimal" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "Sum in Binary: " << bitset<8>(sum) << endl;
            break;
        case 2:
            cout << "Sum in Octal: " << oct << sum << endl;
            break;
        case 3:
            cout << "Sum in Hexadecimal: " << hex << sum << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
