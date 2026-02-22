// COMSC-210 | Lab 11 | Joaquin Felix

#include <iostream>
#include <string>

using namespace std;

// Struct: Student
// Represents one student with a dynamic array of courses
struct Student {
    string name;
    int studentID;

    // Pointer to dynamic array of course names
    string* courses;
    int courseCount;
};


void addCourse(Student& student, string course);



int main (){

    
}
void addCourse(Student& student, string course){
    // Create a new array with one extra slot
    string* newCourses = new string[student.courseCount + 1];

    // Copy existing courses into new array
    for (int i = 0; i < student.courseCount; i++){
        newCourses[i] = student.courses[i];
    }

    newCourses[student.courseCount] = course;
    delete[] student.courses;
    student.courses = newCourses;
    student.courseCount++;
}

void printStudent(const Student& student){
    cout << "Student Name: " << student.name << endl;
    cout << "Student ID: " << student.studentID << endl;
    cout << "Enrolled Courses: ";

    if (student.courseCount == 0){
        cout << "None";
    } else {
        for (int i = 0; i < student.courseCount; i+){
            cout << student.course[i];
            if (i < student.courseCount - 1){
                cout << ", ";
            }
        }
    }
}
