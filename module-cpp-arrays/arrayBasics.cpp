// Lab 10 companion program: one-dimensional array basics.
// Declares an array with an initializer list, accesses elements by
// index (indices begin at 0), and traverses the array with a for loop.

#include <iostream>
using namespace std;

int main()
{
    int numbers[5] = {10, 20, 30, 40, 50};

    // Accessing individual elements
    cout << numbers[0] << endl;  // 10
    cout << numbers[2] << endl;  // 30

    // Traversing the array
    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << endl;
    }

    return 0;
}
