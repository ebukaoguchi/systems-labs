#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    string major;
    string classification;
    int age;
    string favoriteLanguage;

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Enter your major: ";
    getline(cin, major);

    cout << "Enter your classification: ";
    getline(cin, classification);

    cout << "Enter your age: ";
    cin >> age;
    cin.ignore();

    cout << "Enter your favorite programming language: ";
    getline(cin, favoriteLanguage);

    cout << endl;
    cout << "----- Student Profile -----" << endl;
    cout << "Name: " << name << endl;
    cout << "Major: " << major << endl;
    cout << "Classification: " << classification << endl;
    cout << "Age: " << age << endl;
    cout << "Favorite Programming Language: " << favoriteLanguage << endl;

    return 0;
}
