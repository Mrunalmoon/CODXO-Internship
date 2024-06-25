#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course {
public:
    string courseName;
    int courseCredits;

    Course(const string &name, int credits) : courseName(name), courseCredits(credits) {}
};

class Student {
public:
    string name;
    int age;
    vector<Course> courses;

    Student(const string &name, int age) : name(name), age(age) {}

    void addCourse(const Course &course) {
        courses.push_back(course);
    }

    void displayCourses() const {
        cout << "Courses for " << name << ":" << endl;
        for (const auto &course : courses) {
            cout << "Course Name: " << course.courseName << ", Credits: " << course.courseCredits << endl;
        }
    }
};

class SchoolManagementSystem {
public:
    vector<Student> students;

    void addStudent(const string &name, int age) {
        students.emplace_back(name, age);
    }

    void addCourseToStudent(const string &studentName, const string &courseName, int credits) {
        for (auto &student : students) {
            if (student.name == studentName) {
                student.addCourse(Course(courseName, credits));
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    void displayStudentDetails(const string &studentName) const {
        for (const auto &student : students) {
            if (student.name == studentName) {
                cout << "Name: " << student.name << ", Age: " << student.age << endl;
                student.displayCourses();
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
};

int main() {
    SchoolManagementSystem sms;

    int choice;
    do {
        cout << "\n1. Add Student\n2. Add Course to Student\n3. Display Student Details\n4. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int age;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student age: ";
                cin >> age;
                sms.addStudent(name, age);
                break;
            }
            case 2: {
                string studentName, courseName;
                int credits;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, studentName);
                cout << "Enter course name: ";
                getline(cin, courseName);
                cout << "Enter course credits: ";
                cin >> credits;
                sms.addCourseToStudent(studentName, courseName, credits);
                break;
            }
            case 3: {
                string studentName;
                cout << "Enter student name: ";
