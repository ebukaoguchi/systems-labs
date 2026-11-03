#include <iostream>

using namespace std;

// Function prototypes
void showMenu();
int add(int, int);
int subtract(int, int);
int multiply(int, int);
double divide(int, int);

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

        if (choice == 1)
        {
            cout << "Result: " << add(a, b) << endl;
        }
        else if (choice == 2)
        {
            cout << "Result: " << subtract(a, b) << endl;
        }
        else if (choice == 3)
        {
            cout << "Result: " << multiply(a, b) << endl;
        }
        else if (choice == 4)
        {
            if (b == 0)
            {
                cout << "Cannot divide by zero\n";
            }
            else
            {
                cout << "Result: " << divide(a, b) << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting program...\n";
        }
        else
        {
            cout << "Invalid choice, try again\n";
        }

    } while (choice != 5);

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
    cout << "5. Exit\n";
}

// Addition
int add(int a, int b)
{
    return a + b;
}

// Subtraction
int subtract(int a, int b)
{
    return a - b;
}

// Multiplication
int multiply(int a, int b)
{
    return a * b;
}

// Division
double divide(int a, int b)
{
    return static_cast<double>(a) / b;
}
