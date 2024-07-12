#include <iostream>

using namespace std;

int main() {
    int numCourses;
    double totalPoints = 0.0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        double points;
        cout << "Enter grade points for course " << (i + 1) << ": ";
        cin >> points;
        totalPoints += points;
    }

    double cgpa = totalPoints / numCourses;

    cout << "CGPA: " << cgpa << endl;

    return 0;
}
