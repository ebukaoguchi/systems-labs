#include <iostream>

using namespace std;

// Function prototypes
void showMenu();
void add(int, int);
void subtract(int, int);
void multiply(int, int);
void divide(int, int);

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

        switch (choice)
        {
            case 1:
                add(a, b);
                break;
            case 2:
                subtract(a, b);
                break;
            case 3:
                multiply(a, b);
                break;
            case 4:
                divide(a, b);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
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
void add(int a, int b)
{
    cout << "Result: " << a + b << endl;
}

// Subtraction
void subtract(int a, int b)
{
    cout << "Result: " << a - b << endl;
}

// Multiplication
void multiply(int a, int b)
{
    cout << "Result: " << a * b << endl;
}

// Division
void divide(int a, int b)
{
    if (b == 0)
    {
        cout << "Cannot divide by zero\n";
        return;
    }

    cout << "Result: " << static_cast<double>(a) / b << endl;
}
