// Lab 10 companion program: printing a three-dimensional array.
// Three nested loops: the outer loop selects the layer, the middle
// loop the row within the layer, the inner loop the column.

#include <iostream>
using namespace std;

int main()
{
    int numbers[2][2][3] = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}
    };

    for (int layer = 0; layer < 2; layer++)
    {
        cout << "Layer " << layer + 1 << endl;

        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                cout << numbers[layer][row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
