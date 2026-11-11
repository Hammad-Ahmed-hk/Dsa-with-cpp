#include <iostream>
#include <string>

using namespace std;

// ?? Structure to represent a student
struct Student {
    string name;       
    int rollNumber;   
    int semester;     
    float gpa;         
    Student* next;     

    // Constructor to initialize student data
    Student(string n, int r, int s, float g) : name(n), rollNumber(r), semester(s), gpa(g), next(nullptr) {}
};

// ??? Class to manage the student records using singly linked list
class StudentManagementSystem {
private:
    Student* head;  // Pointer to the first student in the list

public:
    // Constructor initializes the head to nullptr (empty list)
    StudentManagementSystem() : head(nullptr) {}

    // 1?? Add student at the start
    void addStudentAtStart(string name, int rollNumber, int semester, float gpa) {
        Student* newStudent = new Student(name, rollNumber, semester, gpa);
        newStudent->next = head;  // New student points to the current head
        head = newStudent;        // Head updated to the new student
        cout << "? Student added at the start.\n";
    }

    // 2?? Add student at the end
    void addStudentAtEnd(string name, int rollNumber, int semester, float gpa) {
        Student* newStudent = new Student(name, rollNumber, semester, gpa);
        if (!head) {
            head = newStudent;  // If list is empty, new student becomes the head
        } else {
            Student* temp = head;
            while (temp->next) {
                temp = temp->next;  // Traverse to the last node
            }
            temp->next = newStudent;  // Link the new student at the end
        }
        cout << "? Student added at the end.\n";
    }

    // 3?? Add student at a specific position
    void addStudentAtPosition(string name, int rollNumber, int semester, float gpa, int position) {
        if (position <= 1) {
            addStudentAtStart(name, rollNumber, semester, gpa);
            return;
        }

        Student* newStudent = new Student(name, rollNumber, semester, gpa);
        Student* temp = head;
        int currentPos = 1;

        while (temp && currentPos < position - 1) {
            temp = temp->next;
            currentPos++;
        }

        if (!temp) {
            addStudentAtEnd(name, rollNumber, semester, gpa);
        } else {
            newStudent->next = temp->next;
            temp->next = newStudent;
            cout << "? Student added at position " << position << ".\n";
        }
    }

    // 4?? Delete student by roll number
    void deleteStudentByRollNumber(int rollNumber) {
        if (!head) {
            cout << "? No records found.\n";
            return;
        }

        // If the student to delete is the first one
        if (head->rollNumber == rollNumber) {
            Student* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "? Student with Roll Number " << rollNumber << " deleted.\n";
            return;
        }

        Student* temp = head;
        while (temp->next && temp->next->rollNumber != rollNumber) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "? Student with Roll Number " << rollNumber << " not found.\n";
            return;
        }

        Student* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "? Student with Roll Number " << rollNumber << " deleted.\n";
    }

    // 5?? Display all student records
    void displayStudents() {
        if (!head) {
            cout << "?? No student records to display.\n";
            return;
        }

        cout << "\n?? Student Records:\n";
        Student* temp = head;
        while (temp) {
            cout << "------------------------------\n";
            cout << "?? Name: " << temp->name << "\n";
            cout << "?? Roll Number: " << temp->rollNumber << "\n";
            cout << "?? Semester: " << temp->semester << "\n";
            cout << "?? GPA: " << temp->gpa << "\n";
            temp = temp->next;
        }
        cout << "------------------------------\n";
    }

    // Destructor to free allocated memory
    ~StudentManagementSystem() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// ?? Main function: Provides menu-driven interface
int main() {
    StudentManagementSystem sms;
    int choice, rollNumber, semester, position;
    float gpa;
    string name;

    do {
        cout << "\n====== ?? Student Management System Menu ======\n";
        cout << "1?? Add Student at Start\n";
        cout << "2?? Add Student at End\n";
        cout << "3?? Add Student at Specific Position\n";
        cout << "4?? Delete Student by Roll Number\n";
        cout << "5?? Display All Students\n";
        cout << "6?? Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Roll Number: "; cin >> rollNumber;
                cout << "Enter Semester: "; cin >> semester;
                cout << "Enter GPA: "; cin >> gpa;
                sms.addStudentAtStart(name, rollNumber, semester, gpa);
                break;

            case 2:
                cout << "\nEnter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Roll Number: "; cin >> rollNumber;
                cout << "Enter Semester: "; cin >> semester;
                cout << "Enter GPA: "; cin >> gpa;
                sms.addStudentAtEnd(name, rollNumber, semester, gpa);
                break;

            case 3:
                cout << "\nEnter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Roll Number: "; cin >> rollNumber;
                cout << "Enter Semester: "; cin >> semester;
                cout << "Enter GPA: "; cin >> gpa;
                cout << "Enter Position: "; cin >> position;
                sms.addStudentAtPosition(name, rollNumber, semester, gpa, position);
                break;

            case 4:
                cout << "\nEnter Roll Number to Delete: "; cin >> rollNumber;
                sms.deleteStudentByRollNumber(rollNumber);
                break;

            case 5:
                sms.displayStudents();
                break;

            case 6:
                cout << "?? Exiting the system. Goodbye!\n";
                break;

            default:
                cout << "? Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}