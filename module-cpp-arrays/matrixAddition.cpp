// Lab 10 companion program: adding two 2 x 3 matrices element by element.
// Each element of the sum is the sum of the elements at the same
// row and column in the two source arrays.

#include <iostream>
using namespace std;

int main()
{
    int numbers[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    int numbers2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int sum[2][3];

    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            sum[row][col] = numbers[row][col] + numbers2[row][col];
            cout << sum[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
