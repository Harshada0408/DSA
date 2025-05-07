#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent() {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.rollNumber;
    cin.ignore(); 
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Division: ";
    getline(cin, s.division);
    cout << "Enter Address: ";
    getline(cin, s.address);

    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open()) {
        outFile << s.rollNumber << endl;
        outFile << s.name << endl;
        outFile << s.division << endl;
        outFile << s.address << endl;
        outFile.close();
        cout << "Student added successfully!" << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

void deleteStudent() {
    int rollNumber;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNumber;

    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");
    bool found = false;
    Student s;

    if (inFile.is_open() && outFile.is_open()) {
        while (inFile >> s.rollNumber) {  
            inFile.ignore(); // Ignore the newline character
            getline(inFile, s.name);
            getline(inFile, s.division);
            getline(inFile, s.address);

            if (s.rollNumber == rollNumber) {
                found = true;
                cout << "Deleting student: " << s.name << endl;
                continue; // Skip writing this student to the temp file
            }
            outFile << s.rollNumber << endl;
            outFile << s.name << endl;
            outFile << s.division << endl;
            outFile << s.address << endl;
        }
        inFile.close();
        outFile.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (found) {
            cout << "Student deleted successfully!" << endl;
        } else {
            cout << "Student with Roll Number " << rollNumber << " not found." << endl;
        }
    } else {
        cout << "Unable to open file." << endl;
    }
}

void displayStudent() {
    int rollNumber;
    cout << "Enter Roll Number to display: ";
    cin >> rollNumber;

    ifstream inFile("students.txt");
    bool found = false;
    Student s;

    if (inFile.is_open()) {
        while (inFile >> s.rollNumber) {
            inFile.ignore(); // Ignore the newline character
            getline(inFile, s.name);
            getline(inFile, s.division);
            getline(inFile, s.address);

            if (s.rollNumber == rollNumber) {
                found = true;
                cout << "Roll Number: " << s.rollNumber << endl;
                cout << "Name: " << s.name << endl;
                cout << "Division: " << s.division << endl;
                cout << "Address: " << s.address << endl;
                break;
            }
        }
        inFile.close();

        if (!found) {
            cout << "Student with Roll Number " << rollNumber << " not found." << endl;
        }
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\nStudent Information System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
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
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}