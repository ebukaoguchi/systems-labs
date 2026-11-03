#include <iostream>
#include <limits>

using namespace std;

// Function prototypes
void showMenu();
void add(double, double);
void subtract(double, double);
void multiply(double, double);
void divide(double, double);

int main()
{
    int choice;
    double a, b;

    do
    {
        showMenu();

        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Enter numbers only.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        if (choice >= 1 && choice <= 4)
        {
            cout << "Enter two numbers: ";

            if (!(cin >> a >> b))
            {
                cout << "Invalid input! Enter numbers only.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }
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

void add(double a, double b)
{
    cout << "Result: " << a + b << endl;
}

void subtract(double a, double b)
{
    cout << "Result: " << a - b << endl;
}

void multiply(double a, double b)
{
    cout << "Result: " << a * b << endl;
}

void divide(double a, double b)
{
    if (b == 0)
    {
        cout << "Cannot divide by zero!" << endl;
        return;
    }

    cout << "Result: " << a / b << endl;
}
