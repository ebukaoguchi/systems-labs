// Lab 10 companion program: printing a two-dimensional array.
// The outer loop selects the row; the inner loop walks the columns
// of that row. One newline ends each row.

#include <iostream>
using namespace std;

int main()
{
    int numbers[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << numbers[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
