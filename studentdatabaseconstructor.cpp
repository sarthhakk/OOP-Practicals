// Develop an object oriented program in C++ to create a database of student information 
// systems containing the following information: Name, Roll number, Class, division, Date of Birth, Aadhar number,
//  Blood group, Contact address, telephone number, etc . 
// Write the code to illustrate the use of default constructor, parametrized constructor and copy constructor.



#include <iostream>
#include<string>
using namespace std;

class Student{

    private:
        string name;
        int rollNo;
        string className;
        string dob;
        string aadharNo;
        string bloodGroup;
        string contactAddress;
        string telephoneNo;
        
    public:
    Student()
    {
        cout<<"\nDefault Constructor called !"<<endl;
    }
    Student(string name, int rollNo, string className, string dob, string aadharNo,
    string bloodGroup, string contactAddress, string telephoneNo)
    {
          cout<<"\nParamterized construtor called !!"<<endl;
          this->name=name;
          this->rollNo=rollNo;
          this->className=className;
          this->dob=dob;
          this->aadharNo=aadharNo;
          this->bloodGroup=bloodGroup;
          this->contactAddress=contactAddress;
          this->telephoneNo=telephoneNo;
    }
    
    Student(Student &obj)
    {
        cout<<"\nCopy Constructor called !!"<<endl;
        this->name=obj.name;
        this->rollNo=obj.rollNo;
        this->className=obj.className;
        this->dob=obj.dob;
        this->aadharNo=obj.aadharNo;
        this->bloodGroup=obj.bloodGroup;
        this->contactAddress=obj.contactAddress;
        this->telephoneNo=obj.telephoneNo;
    }
    ~Student()
    {
        cout<<"\nDestructor called !!"<<endl;
    }
    void displayInfo() {
        cout << "\nStudent Information:\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Class: " << className << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Aadhar Number: " << aadharNo << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNo << endl;
    }
};

int main() 
{
    string name, className, dob, aadharNo, bloodGroup, contactAddress, telephoneNo;
    int rollNo;
    cout << "Enter details for the student:\n";
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cout << "Enter Class: ";
    cin >> className;
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    cin >> dob;
    cout << "Enter Aadhar Number: ";
    cin >> aadharNo;
    cout << "Enter Blood Group: ";
    cin >> bloodGroup;
    cout << "Enter Contact Address: ";
    cin >> contactAddress;
    cout << "Enter Telephone Number: ";
    cin >> telephoneNo;
    Student s1;
    Student s2(name, rollNo, className, dob, aadharNo, bloodGroup, contactAddress, telephoneNo);
    s2.displayInfo();
    Student s3(s2);
    s3.displayInfo();
    
    return 0;
}