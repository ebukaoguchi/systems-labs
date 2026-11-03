#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    string input;
    int choice;
    int number;

    cout << "Choose the number system of your input:" << endl;
    cout << "1. Binary" << endl;
    cout << "2. Octal" << endl;
    cout << "3. Decimal" << endl;
    cout << "4. Hexadecimal" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the number: ";
    cin >> input;

    switch (choice)
    {
        case 1:
            number = stoi(input, nullptr, 2);
            break;
        case 2:
            number = stoi(input, nullptr, 8);
            break;
        case 3:
            number = stoi(input, nullptr, 10);
            break;
        case 4:
            number = stoi(input, nullptr, 16);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 0;
    }

    cout << endl;
    cout << "Binary:      " << bitset<8>(number) << endl;
    cout << "Octal:       " << oct << number << endl;
    cout << "Decimal:     " << dec << number << endl;
    cout << "Hexadecimal: " << hex << number << endl;

    return 0;
}
