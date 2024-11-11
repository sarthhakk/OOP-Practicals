// Define a class Complex consisting following:
// Data members:
// a. real
// b. imaginary part
// Member Functions:
// a. One default constructor
// b. Function setComplex () to set the value of real and imaginary part.
// c. Function printComplex() to display
// and
// Four overloaded operator member functions

// i. Operator+ to add two complex numbers.
// ii. Operator * to multiply two complex numbers.
// iii. Operator – to subtract two complex numbers using friend function.
// iv. Operator / to divide two complex numbers using friend function


#include <iostream>
#include<string>
using namespace std;

class Complex
{
    private:
    int real;
    int imag;
    
    public:
    void setComplex()
    {
        cout<<"Enter the Real part: "<<endl;
        cin>>real;
        cout<<"Enter the Imaginary part: "<<endl;
        cin>>imag;
    }
    void printComplex()
    {
        if(imag>0)
        {
             cout<<"The number is: "<<real<<"+"<<imag<<"i"<<endl;
        }
        else{
             cout<<"The number is: "<<real<<imag<<"i"<<endl;
        }
       
    }
    
    Complex operator +(Complex c)
    {
        Complex answer;
        answer.real=real + c.real;
        answer.imag=imag + c.imag;
        return answer;
    } 
    
    Complex operator -(Complex c)
    {
        Complex answer;
        answer.real=real-c.real;
        answer.imag=imag-c.imag;
        return answer;
    }
    
    Complex operator *(Complex c)
    {
        Complex answer;
        answer.real=(real*c.real - imag*c.imag);
        answer.imag = (real * c.imag) + (imag * c.real); 
        return answer;
    }
    
    Complex operator /( Complex c)
    {
        Complex answer;
        answer.real = ((real*c.real) + (imag*c.imag)) / ((c.real*c.real) + (c.imag*c.imag));
        answer.imag = ((imag*c.real) - (real*c.imag)) / ((c.real*c.real) + (c.imag*c.imag));
        return answer;
    }
};
int main()
{
    int ch;
    Complex c1,c2,c3;
    cout<<"Number 1: "<<endl;
    c1.setComplex();
    c1.printComplex();
    cout<<"\nNumber 2: "<<endl;
    c2.setComplex();
    c2.printComplex();
    
    do{
        cout<<"\n----------------------\n"<<"Menu"<<"\n----------------------"<<endl;
        cout<<"1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                c3 = c1 + c2;
                cout<<"\nSum is: "<<endl;
                c3.printComplex();
                break;
            case 2:
                c3= c1- c2;
                cout<<"\nSubtraction is: "<<endl;
                c3.printComplex();
                break;
            case 3:
                c3= c1* c2;
                cout<<"\nMultiplication is: "<<endl;
                c3.printComplex();
                break;    
            case 4:
                c3= c1 / c2;
                cout<<"\nDivision is: "<<endl;
                c3.printComplex();
                break;    
            case 5:
                return 0;
            default:
                cout<<"Enter a valid choice !!"<<endl;
        }
    }while(ch!=5);
    return 0;
}

