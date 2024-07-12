#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
    string studentID;
public:
    Student(string name, int age, string studentID)
        : name(name), age(age), studentID(studentID) {}

    void display() const {
        cout << "Student Name: " << name << "\nAge: " << age 
             << "\nStudent ID: " << studentID << endl;
    }
};

class SchoolManagementSystem {
private:
    vector<Student> students;
public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayStudents() const {
        cout << "Students:\n";
        for (const auto& student : students) {
            student.display();
            cout << "--------\n";
        }
    }
};

int main() {
    SchoolManagementSystem sms;

    // Adding students
    sms.addStudent(Student("Mrunal", 20, "S123"));
    sms.addStudent(Student("Surbhi", 22, "S124"));

    // Display students
    sms.displayStudents();

    return 0;
}
