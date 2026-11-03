#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input = "123abc";
    size_t position;
    int number = stoi(input, &position, 10);

    cout << "Number: " << number << endl;
    cout << "Stopped at position: " << position << endl;

    return 0;
}
