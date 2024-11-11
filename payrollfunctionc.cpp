/*Personal Info name age 
Job Info id designation 
Payroll salary 
—> accept() 
—> display() 
—> calculateSalary() based on Designation 

Multi Level Inheritance*/



#include <iostream>
#include <string>
using namespace std;


class PersonalInfo {
protected:
    string name;
    int age;

public:
    void acceptPersonalInfo() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore(); 
    }

    void displayPersonalInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};


class JobInfo : public PersonalInfo {
protected:
    int id;
    string designation;

public:
    void acceptJobInfo() {
        cout << "Enter Job ID: ";
        cin >> id;
        cin.ignore(); // Clear newline from buffer
        cout << "Enter Designation (Manager, Developer, Intern): ";
        getline(cin, designation);
    }

    void displayJobInfo() {
        cout << "Job ID: " << id << endl;
        cout << "Designation: " << designation << endl;
    }
};


class Payroll : public JobInfo {
private:
    double salary;

public:
    void calculateSalary() {
        if (designation == "Manager") {
            salary = 80000.0;
        } else if (designation == "Developer") {
            salary = 50000.0;
        } else if (designation == "Intern") {
            salary = 20000.0;
        } else {
            salary = 0.0; 
            cout << "Unknown designation, cannot calculate salary." << endl;
        }
    }

    void accept() {
        acceptPersonalInfo();
        acceptJobInfo();
    }

    void display() {
        displayPersonalInfo();
        displayJobInfo();
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Payroll employee;

    cout << "Enter Employee Details:" << endl;
    employee.accept();

    employee.calculateSalary();

    cout << "\nEmployee Details:" << endl;
    employee.display();

    return 0;
}