#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double length, width;
    double area, perimeter;

    cout << "Enter the length: ";
    cin >> length;

    cout << "Enter the width: ";
    cin >> width;

    area = length * width;
    perimeter = 2 * (length + width);

    cout << fixed << setprecision(2);
    cout << "Area: " << area << endl;
    cout << "Perimeter: " << perimeter << endl;

    return 0;
}
