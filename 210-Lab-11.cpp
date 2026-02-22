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

void printStudent(const Student& student);

int main (){
    const int STUDENT_COUNT = 3;

    Student* students = new Student[STUDENT_COUNT];
    
    // Initialize each student's course pointer and count
    for (int i = 0; i < STUDENT_COUNT; i++){
        students[i].courses = nullptr;
        students[i].courseCount = 0;
    }

    //Assign basic information to each student
    students[0].name = "John";
    students[0].studentID = 1001;

    students[1].name = "Billy";
    students[1].studentID = 1002;

    students[2].name = "Danny";
    students[2].studentID = 1003;

    // Add courses to each student
    addCourse(students[0], "Math 101");
    addCourse(students[0], "English 101");

    addCourse(students[1], "Computer Science 101");

    addCourse(students[2], "History 101");
    addCourse(students[2], "Biology 101");
    addCourse(students[2], "Chemistry 101");

    cout << "UNIVERSITY ENROLLMENT SYSTEM" << endl;
    cout << "============================" << endl;

    // Print all students
    for(int i = 0; i < STUDENT_COUNT; i++){
        printStudent(students[i]);
    }

    // Clean up dynamic memory
    for (int i = 0; i < STUDENT_COUNT; i++){
        delete[] students[i].courses;
    }
    delete[] students;

    return 0;
    
}

// addCourse() adds a new course to a student
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


//printStudent() prints all the information on a student
void printStudent(const Student& student){
    cout << "Student Name: " << student.name << endl;
    cout << "Student ID: " << student.studentID << endl;
    cout << "Enrolled Courses: ";

    if (student.courseCount == 0){
        cout << "None";
    } else {
        for (int i = 0; i < student.courseCount; i++){
            cout << student.courses[i];
            if (i < student.courseCount - 1){
                cout << ", ";
            }
        }
    }
    cout << endl;
    cout << "-----------------------------" << endl;
}
