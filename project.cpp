
#include <iostream>
using namespace std;

const int MAX = 100;

// Student Data Arrays
int rollNo[MAX];
char name[MAX][50];
int age[MAX];
float marks[MAX];
char grade[MAX];

int totalStudents = 0;

// Function Prototypes
void menu();
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
char calculateGrade(float m);

int main()
{
    int choice;

    do
    {
        menu();
        cin >> choice;
if(choice == 1)
{
    addStudent();
}
else if(choice == 2)
{
    displayStudents();
}
else if(choice == 3)
{
    searchStudent();
}
else if(choice == 4)
{
    updateStudent();
}
else if(choice == 5)
{
    deleteStudent();
}
else if(choice == 6)
{
    cout << "\nProgram Ended...\n";
}
else
{
    cout << "\nInvalid Choice!\n";
}
        

    } while(choice != 6);

    return 0;
}

// Menu Function
void menu()
{
    cout << "\n====================================";
    cout << "\n SCHOOL MANAGEMENT SYSTEM";
    cout << "\n====================================";
    cout << "\n1. Add Student";
    cout << "\n2. Display All Students";
    cout << "\n3. Search Student";
    cout << "\n4. Update Student";
    cout << "\n5. Delete Student";
    cout << "\n6. Exit";
    cout << "\n====================================";
    cout << "\nEnter Your Choice: ";
}

// Grade Function
char calculateGrade(float m)
{
    if(m >= 80)
        return 'A';
    else if(m >= 70)
        return 'B';
    else if(m >= 60)
        return 'C';
    else if(m >= 50)
        return 'D';
    else
        return 'F';
}

// Add Student Function
void addStudent()
{
    if(totalStudents >= MAX)
    {
        cout << "\nStudent Limit Reached!\n";
        return;
    }

    cout << "\nEnter Roll Number: ";
    cin >> rollNo[totalStudents];

    cout << "Enter Student Name: ";
    cin.ignore();
    cin.getline(name[totalStudents], 50);

    cout << "Enter Age: ";
    cin >> age[totalStudents];

    cout << "Enter Marks: ";
    cin >> marks[totalStudents];

    grade[totalStudents] = calculateGrade(marks[totalStudents]);

    totalStudents++;

    cout << "\nStudent Added Successfully!\n";
}

// Display Function
void displayStudents()
{
    if(totalStudents == 0)
    {
        cout << "\nNo Students Found!\n";
        return;
    }

    cout << "\n========== STUDENT RECORD ==========";

    for(int i = 0; i < totalStudents; i++)
    {
        cout << "\n\nStudent " << i + 1;
        cout << "\nRoll Number : " << rollNo[i];
        cout << "\nName        : " << name[i];
        cout << "\nAge         : " << age[i];
        cout << "\nMarks       : " << marks[i];
        cout << "\nGrade       : " << grade[i];
    }

    cout << "\n";
}

// Search Function
void searchStudent()
{
    int searchRoll;
    int found = 0;

    cout << "\nEnter Roll Number to Search: ";
    cin >> searchRoll;

    for(int i = 0; i < totalStudents; i++)
    {
        if(rollNo[i] == searchRoll)
        {
            cout << "\nStudent Found!\n";
            cout << "\nRoll Number : " << rollNo[i];
            cout << "\nName        : " << name[i];
            cout << "\nAge         : " << age[i];
            cout << "\nMarks       : " << marks[i];
            cout << "\nGrade       : " << grade[i];

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        cout << "\nStudent Not Found!\n";
    }
}

// Update Function
void updateStudent()
{
    int updateRoll;
    int found = 0;

    cout << "\nEnter Roll Number to Update: ";
    cin >> updateRoll;

    for(int i = 0; i < totalStudents; i++)
    {
        if(rollNo[i] == updateRoll)
        {
            cout << "\nEnter New Name: ";
            cin.ignore();
            cin.getline(name[i], 50);

            cout << "Enter New Age: ";
            cin >> age[i];

            cout << "Enter New Marks: ";
            cin >> marks[i];

            grade[i] = calculateGrade(marks[i]);

            cout << "\nRecord Updated Successfully!\n";

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        cout << "\nStudent Not Found!\n";
    }
}

// Delete Function
void deleteStudent()
{
    int deleteRoll;
    int found = 0;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> deleteRoll;

    for(int i = 0; i < totalStudents; i++)
    {
        if(rollNo[i] == deleteRoll)
        {
            for(int j = i; j < totalStudents - 1; j++)
            {
                rollNo[j] = rollNo[j + 1];
                age[j] = age[j + 1];
                marks[j] = marks[j + 1];
                grade[j] = grade[j + 1];

                int k = 0;
                while(name[j + 1][k] != '\0')
                {
                    name[j][k] = name[j + 1][k];
                    k++;
                }
                name[j][k] = '\0';
            }

            totalStudents--;
            found = 1;

            cout << "\nStudent Deleted Successfully!\n";
            break;
        }
    }

    if(found == 0)
    {
        cout << "\nStudent Not Found!\n";
    }
}
