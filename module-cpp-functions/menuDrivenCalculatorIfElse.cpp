#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void showMenu();
void add(int, int);
void subtract(int, int);
void multiply(int, int);
void divide(int, int);
void saveResult(int, int, char, double);
void viewResults();

int main()
{
    int choice, a, b;

    do
    {
        showMenu();

        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        // Menu selection using if-else
        if (choice == 1)
        {
            add(a, b);
        }
        else if (choice == 2)
        {
            subtract(a, b);
        }
        else if (choice == 3)
        {
            multiply(a, b);
        }
        else if (choice == 4)
        {
            divide(a, b);
        }
        else if (choice == 5)
        {
            viewResults();
        }
        else if (choice == 6)
        {
            cout << "Exiting program...\n";
        }
        else
        {
            cout << "Invalid choice, try again\n";
        }

    } while (choice != 6);

    return 0;
}

// Display menu
void showMenu()
{
    cout << "\n===== CALCULATOR MENU =====\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. View Saved Results\n";
    cout << "6. Exit\n";
}

// Addition
void add(int a, int b)
{
    int result = a + b;

    cout << "Result: " << result << endl;

    saveResult(a, b, '+', result);
}

// Subtraction
void subtract(int a, int b)
{
    int result = a - b;

    cout << "Result: " << result << endl;

    saveResult(a, b, '-', result);
}

// Multiplication
void multiply(int a, int b)
{
    int result = a * b;

    cout << "Result: " << result << endl;

    saveResult(a, b, '*', result);
}

// Division
void divide(int a, int b)
{
    if (b == 0)
    {
        cout << "Cannot divide by zero\n";
        return;
    }

    double result = static_cast<double>(a) / b;

    cout << "Result: " << result << endl;

    saveResult(a, b, '/', result);
}

// Write results to file
void saveResult(int a, int b, char op, double result)
{
    ofstream outFile("results.txt", ios::app);

    if (!outFile)
    {
        cout << "Error opening file for writing.\n";
        return;
    }

    outFile << a << " " << op << " " << b
            << " = " << result << endl;

    outFile.close();

    cout << "Result saved successfully!\n";
}

// Read results from file
void viewResults()
{
    ifstream inFile("results.txt");

    if (!inFile)
    {
        cout << "No saved results found.\n";
        return;
    }

    string line;

    cout << "\n===== SAVED RESULTS =====\n";

    while (getline(inFile, line))
    {
        cout << line << endl;
    }

    inFile.close();
}
