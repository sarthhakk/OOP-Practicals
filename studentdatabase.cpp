#include <iostream>
#include<string>
using namespace std;


class Student
{
    private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string aadharNumber;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;

    static int count;

    public:
    Student(string name, int rollNumber, string studentClass, char division, string dob,
    string aadharNumber, string bloodGroup, string contactAddress, string telephoneNumber)
    {
        this->name = name;
        this->rollNumber = rollNumber;
        this->studentClass = studentClass;
        this->division = division;
        this->dob = dob;
        this->aadharNumber = aadharNumber;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        count++;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll Number: "<<rollNumber<<endl;
        cout<<"Student Class: "<<studentClass<<endl;
        cout<<"Division: "<<division<<endl;
        cout<<"Date of Birth: "<<dob<<endl;
        cout<<"Aadhar Number: "<<aadharNumber<<endl;
        cout<<"Blood Group: "<<bloodGroup<<endl;
        cout<<"Contact Address: "<<contactAddress<<endl;
        cout<<"Telephone Number: "<<telephoneNumber<<endl;
        }

        static int returnCount()
        {
            return count;
        }
};
int Student::count=0;

int main(){
    Student s1("Sarthak Vyavahare", 101,"10th", 'A', "06-01-2005", "1212121221", "O+", "Kothrud", "12323");
    Student s2("Atharva",102, "10th", 'B', "02-02-2005", "987654321012", "A+", "456 Elm St,City", "0987654321");

    cout<<"\nStudent 1:"<<endl;
    s1.display();
    cout<<"\nStudent 2:"<<endl;
    s2.display();
    cout<<"\nTotal Students: "<<Student::returnCount()<<endl;
    return 0;
}







