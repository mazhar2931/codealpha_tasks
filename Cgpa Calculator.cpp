#include <iostream>
#include <string>
using namespace std;
float gradeToPoint(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    if (grade == "B" || grade == "b") return 3.0;
    if (grade == "C" || grade == "c") return 2.0;
    if (grade == "D" || grade == "d") return 1.0;
    return 0.0;
}

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    float credit, totalCredits = 0, gradePoints = 0;
    string grade;

    cout << "\n--- Enter Course Data ---\n";
    for (int i = 1; i <= n; i++) {
        cout << "\nCourse " << i << " grade (A/B/C/D/F): ";
        cin >> grade;

        cout << "Credit hours: ";
        cin >> credit;

        float gp = gradeToPoint(grade) * credit;
        gradePoints += gp;
        totalCredits += credit;

        cout << "Grade Points for Course " << i << ": " << gp << endl;
    }
    float GPA = gradePoints / totalCredits;

    cout << "\n-----------------------------------";
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << gradePoints;
    cout << "\nYour Semester GPA is: " << GPA;
    float prevCGPA, prevCredits;
    cout << "\n\nEnter previous CGPA (enter 0 if none): ";
    cin >> prevCGPA;
    cout << "Enter total previous credits: ";
    cin >> prevCredits;

    float CGPA = (prevCGPA * prevCredits + gradePoints) / (prevCredits + totalCredits);

    cout << "\nYour Overall CGPA is: " << CGPA;
    cout << "\n-----------------------------------\n";

    return 0;
}
