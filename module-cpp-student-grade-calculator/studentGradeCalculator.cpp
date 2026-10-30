// studentGradeCalculator.cpp
//
// Worked example for SCIS 123 Lab 6, "Putting It All Together":
// a complete C++ program built from functions, combining input,
// arithmetic, if / else if ranges, a switch on a single value,
// and formatted output.
//
// The program asks for a student's name and four scores, then
// prints a grade report. Weights:
//   Final Grade = (Exam Average x 0.50) + (Homework x 0.25) + (Lab x 0.25)
//
// Sample run (from the lab deck):
//   Enter student name: Jane Smith
//   Exam 1 / Enter score: 85
//   Exam 2 / Enter score: 92
//   Homework / Enter score: 88
//   Lab / Enter score: 95
//   ------ GRADE REPORT ------
//   Student: Jane Smith
//   Exam Average: 88.50
//   Homework: 88.00
//   Lab: 95.00
//   Final Grade: 90.00
//   Letter Grade: A
//   Excellent performance!

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
double getScore();
double calculateExamAverage(double, double);
double calculateFinalGrade(double, double, double);
char getLetterGrade(double);
void displayMessage(char);

int main()
{
    string name;
    double exam1, exam2;
    double homework, lab;
    double examAverage;
    double finalGrade;
    char letterGrade;

    // Get student's name
    cout << "Enter student name: ";
    getline(cin, name);

    // Get scores
    cout << "\nExam 1" << endl;
    exam1 = getScore();

    cout << "\nExam 2" << endl;
    exam2 = getScore();

    cout << "\nHomework" << endl;
    homework = getScore();

    cout << "\nLab" << endl;
    lab = getScore();

    // Calculate exam average
    examAverage = calculateExamAverage(exam1, exam2);

    // Calculate final grade
    finalGrade = calculateFinalGrade(examAverage, homework, lab);

    // Determine letter grade
    letterGrade = getLetterGrade(finalGrade);

    // Format decimal output
    cout << fixed << setprecision(2);

    // Display grade report
    cout << "\n------ GRADE REPORT ------" << endl;
    cout << "Student: " << name << endl;
    cout << "Exam Average: " << examAverage << endl;
    cout << "Homework: " << homework << endl;
    cout << "Lab: " << lab << endl;
    cout << "Final Grade: " << finalGrade << endl;
    cout << "Letter Grade: " << letterGrade << endl;

    displayMessage(letterGrade);

    return 0;
}

// Get a score from the user
double getScore()
{
    double score;
    cout << "Enter score: ";
    cin >> score;

    if (score < 0 || score > 100)
    {
        cout << "Invalid score." << endl;
    }

    return score;
}

// Calculate exam average
double calculateExamAverage(double exam1, double exam2)
{
    return (exam1 + exam2) / 2.0;
}

// Calculate weighted final grade
double calculateFinalGrade(double examAverage, double homework, double lab)
{
    return (examAverage * 0.50) + (homework * 0.25) + (lab * 0.25);
}

// Determine letter grade
char getLetterGrade(double grade)
{
    if (grade >= 90)
    {
        return 'A';
    }
    else if (grade >= 80)
    {
        return 'B';
    }
    else if (grade >= 70)
    {
        return 'C';
    }
    else if (grade >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

// Display performance message
void displayMessage(char grade)
{
    switch (grade)
    {
        case 'A':
            cout << "Excellent performance!" << endl;
            break;
        case 'B':
            cout << "Good performance!" << endl;
            break;
        case 'C':
            cout << "Satisfactory performance." << endl;
            break;
        case 'D':
            cout << "Needs improvement." << endl;
            break;
        case 'F':
            cout << "Failing." << endl;
            break;
        default:
            cout << "Invalid grade." << endl;
    }
}
