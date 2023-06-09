/*Company maintains employee information as employee ID, name, designation and
salary. Allow user to add, delete information of employee. Display information of
particular employee. If employee does not exist an appropriate message is displayed.
If it is, then the system displays the employee details. Use index sequential file to
maintain the data.*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Employee {
    int empID;
    char name[50];
    char designation[50];
    float salary;
};

// Function to add employee information
void addEmployee() {
    ofstream file("employee.dat", ios::binary | ios::app);

    Employee emp;
    cout << "Enter employee ID: ";
    cin >> emp.empID;
    cout << "Enter employee name: ";
    cin.ignore();
    cin.getline(emp.name, 50);
    cout << "Enter employee designation: ";
    cin.getline(emp.designation, 50);
    cout << "Enter employee salary: ";
    cin >> emp.salary;

    file.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
    file.close();

    cout << "Employee information added successfully!" << endl;
}

// Function to delete employee information
void deleteEmployee() {
    ifstream file("employee.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    int empID;
    cout << "Enter employee ID to delete: ";
    cin >> empID;

    Employee emp;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.empID != empID) {
            tempFile.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found) {
        cout << "Employee information deleted successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

// Function to display employee information
void displayEmployee() {
    ifstream file("employee.dat", ios::binary);

    int empID;
    cout << "Enter employee ID to display: ";
    cin >> empID;

    Employee emp;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.empID == empID) {
            cout << "Employee ID: " << emp.empID << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee not found!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Add employee\n";
        cout << "2. Delete employee\n";
        cout << "3. Display employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
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

