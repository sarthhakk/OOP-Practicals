// Develop an object oriented program in C++ to create a base class Employee and derived classes
// SalariedEmployee, HourlyEmployee and CommisionEmployee.
// The class Employee has data members: string Ename, int EmpID and has a default constructor
// and parameterized constructor. It has two virtual functions accept() to receive data member
// values from the user and display() to output data member values; and a pure virtual function
// earnings().
// The class SalariedEmployee has a data member: double weeklysalary and has a default
// constructor and parameterized constructor. The function earnings() displays weekly salary.
// The class HourlyEmployee has data members: double wage, double hours and double
// Hourlysalary; and has a default constructor and parameterized constructor. The function
// earnings() is defined as
// if(hours&lt;40)
// { Hourlysalary= hours*wage; }
// else
// { Hourlysalary=40*wage + ((hours-40)*wage)*1.5; }
// The class CommisionEmployee has data members: double grossSales, double commissionRate,
// double Commisionsalary; and has a default constructor and parameterized constructor. The
// function earnings() is defined as Commisionsalary = grossSales * commissionRate;
// Create objects of derived classes and display their earnings?



#include<iostream>
#include<string>
using namespace std;

class Employee
{
    private:
        string ename;
        int empId;
        
    public:
        Employee(string ename = "", int empId = 0)
        {
            this->ename = ename;
            this->empId = empId;
        }
        
        void display()
        {
            cout<<"Employee Name: "<<ename<<endl;
            cout<<"Employee Id: "<<empId<<endl;
        }
        
        virtual double earnings() = 0;
};

class SalariedEmployee: public Employee
{
    private:
        double weeklySal;
    
    public:
        SalariedEmployee(string ename = "", int empId = 0, double weeklySal = 0.0) 
            : Employee(ename, empId)
        {
            this->weeklySal = weeklySal;
        }
        
        void display()
        {
            Employee::display();
            cout<<"Weekly Salary: "<<weeklySal<<endl;
        }
        
        double earnings()
        {
            return weeklySal;
        }
};

class HourlyEmployee: public Employee
{
    private:
        double wage;
        double hours;
    
    public:
        HourlyEmployee(string ename = "", int empId = 0, double wage = 0.0, double hours = 0.0) 
            : Employee(ename, empId)
        {
            this->wage = wage;
            this->hours = hours;
        }
        
        void display()
        {
            Employee::display();
            cout << "Wage: " << wage << endl;
            cout << "Hours: " << hours << endl;
        }
        double earnings()
        {
            if (hours < 40) 
            {
                return hours * wage;
            } 
            else 
            {
                return 40 * wage + ((hours - 40) * wage * 1.5);
            }
        }
};

class CommissionEmployee : public Employee
{
    private:
        double grossSales;
        double commissionRate;
    
    public:
        CommissionEmployee(string ename = "", int empId = 0, double grossSales = 0.0, double commissionRate = 0.0) 
            : Employee(ename, empId)
        {
            this->grossSales = grossSales;
            this->commissionRate = commissionRate;
        }
        
        void display()
        {
            Employee::display();
            cout << "Gross Sales: " << grossSales << endl;
            cout << "Commission Rate: " << commissionRate << endl;
        }
        double earnings()
        {
            return grossSales * commissionRate;
        }
}; 
int main()
{
    SalariedEmployee se("Aditya", 1, 1000.0);
    HourlyEmployee he("Aryan", 2, 20.0, 45.0);
    CommissionEmployee ce("Rahul", 3, 5000.0, 0.1);

    SalariedEmployee demo; 
    se.display();
    cout<<"Earnings: "<<se.earnings()<<endl;
    
    HourlyEmployee demo1;
    he.display();
    cout<<"Earnings: "<<he.earnings()<<endl;
    
    CommissionEmployee demo2; 
    ce.display();
    cout<<"Earnings: "<<ce.earnings()<<endl;
    return 0;
}