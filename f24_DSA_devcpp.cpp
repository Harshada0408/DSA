#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX = 100; // Max number of records

struct Employee {
    int id;
    char name[30];
    char designation[30];
    float salary;
};

struct IndexEntry {
    int id;
    long pos;
};

IndexEntry indexList[MAX];
int indexCount = 0;

void loadIndex() {
    indexCount = 0;
    ifstream indexFile("index.dat", ios::binary);
    if (!indexFile) return;

    while (indexFile.read((char*)&indexList[indexCount], sizeof(IndexEntry))) {
        indexCount++;
    }
    indexFile.close();
}

void saveIndex() {
    ofstream indexFile("index.dat", ios::binary | ios::trunc);
    for (int i = 0; i < indexCount; i++) {
        indexFile.write((char*)&indexList[i], sizeof(IndexEntry));
    }
    indexFile.close();
}

bool idExists(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexList[i].id == id)
            return true;
    }
    return false;
}

void sortIndex() {
    for (int i = 0; i < indexCount - 1; i++) {
        for (int j = i + 1; j < indexCount; j++) {
            if (indexList[i].id > indexList[j].id) {
                IndexEntry temp = indexList[i];
                indexList[i] = indexList[j];
                indexList[j] = temp;
            }
        }
    }
}

void addEmployee() {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;

    loadIndex();
    if (idExists(emp.id)) {
        cout << "Employee ID already exists.\n";
        return;
    }

    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(emp.name, 30);
    cout << "Enter Designation: ";
    cin.getline(emp.designation, 30);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    ofstream dataFile("employee.dat", ios::binary | ios::app);
    long pos = dataFile.tellp();
    dataFile.write((char*)&emp, sizeof(Employee));
    dataFile.close();

    indexList[indexCount].id = emp.id;
    indexList[indexCount].pos = pos;
    indexCount++;

    sortIndex();
    saveIndex();
    cout << "Employee added successfully.\n";
}

int findIndexPosition(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexList[i].id == id)
            return i;
    }
    return -1;
}

void displayEmployee() {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;

    loadIndex();
    int idx = findIndexPosition(id);
    if (idx == -1) {
        cout << "Employee with ID " << id << " not found.\n";
        return;
    }

    ifstream dataFile("employee.dat", ios::binary);
    dataFile.seekg(indexList[idx].pos);
    Employee emp;
    dataFile.read((char*)&emp, sizeof(Employee));
    dataFile.close();

    cout << "\n--- Employee Details ---\n";
    cout << "ID: " << emp.id << "\n";
    cout << "Name: " << emp.name << "\n";
    cout << "Designation: " << emp.designation << "\n";
    cout << "Salary: " << emp.salary << "\n";
}

void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    loadIndex();
    int idx = findIndexPosition(id);
    if (idx == -1) {
        cout << "Employee with ID " << id << " not found.\n";
        return;
    }

    ifstream dataFile("employee.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);
    Employee emp;
    long newPos = 0;
    int newIndexCount = 0;
    IndexEntry newIndexList[MAX];

    while (dataFile.read((char*)&emp, sizeof(Employee))) {
        if (emp.id != id) {
            tempFile.write((char*)&emp, sizeof(Employee));
            newIndexList[newIndexCount].id = emp.id;
            newIndexList[newIndexCount].pos = newPos;
            newPos += sizeof(Employee);
            newIndexCount++;
        }
    }

    dataFile.close();
    tempFile.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    for (int i = 0; i < newIndexCount; i++) {
        indexList[i] = newIndexList[i];
    }
    indexCount = newIndexCount;

    saveIndex();
    cout << "Employee deleted successfully.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employee\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            displayEmployee();
            break;
        case 3:
            deleteEmployee();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

