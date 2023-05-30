#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student {
    int rollNumber;
    char name[50];
    char division[10];
    char address[100];
};

// Function to add student information
void addStudent() {
    ofstream file("students.dat", ios::binary | ios::app);

    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cout << "Enter name: ";
    cin.ignore();
    cin.getline(student.name, 50);
    cout << "Enter division: ";
    cin >> student.division;
    cout << "Enter address: ";
    cin.ignore();
    cin.getline(student.address, 100);

    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    file.close();

    cout << "Student information added successfully!" << endl;
}

// Function to delete student information
void deleteStudent() {
    ifstream file("students.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    int rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber != rollNumber) {
            tempFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        cout << "Student information deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

// Function to display student information
void displayStudent() {
    ifstream file("students.dat", ios::binary);

    int rollNumber;
    cout << "Enter roll number to display: ";
    cin >> rollNumber;

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber == rollNumber) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student not found!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Add student\n";
        cout << "2. Delete student\n";
        cout << "3. Display student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}


