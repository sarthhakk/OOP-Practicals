/*Develop an object-oriented program in C++ to create a class Hotel for hotel
booking system.
The class Hotel has data members: string cust_name, int cust_id, int income, string
city, and string room_type and has a default constructor. It has functions accept ()
and display () to output data member values.
The class Hotel has member functions as: getage(),getincome(),getcity() and
getrrom_type().
Throw four exceptions as :
1.If the age is not between 18 and 55.
2.If income is not between 50000 and 100000.
3.If the city is not Pune or Mumbai
*/


#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class AgeException : public exception {
public:
    const char* what() const throw() {
        return "Invalid Age !! Age should be between 18 to 55";
    }
};

class IncomeException : public exception 
{
public:
    const char* what() const throw() {
        return "Invalid Income !! Income should be between 50000 and 100000";
    }
};

class CityException : public exception {
public:
    const char* what() const throw() {
        return "Invalid City !! City should be Pune or Mumbai";
    }
};

class RoomTypeException : public exception {
public:
    const char* what() const throw() {
        return "Invalid Room Type !! Room type should be Delux or Super Delux";
    }
};

class Hotel {
private:
    string cust_name;
    int cust_id;
    int age;
    int income;
    string city;
    string room_type;

public:
    void accept() {
        cout << "Enter Customer ID: ";
        cin >> cust_id;
        cout << "Enter Customer Name: ";
        cin >> cust_name;
        getage();
        getincome();
        getcity();
        getroom_type();
    }

    void getage() {
        cout << "Enter Age: ";
        cin >> age;
        if (age < 18 || age > 55) {
            throw AgeException();
        }
    }

    void getincome() {
        cout << "Enter income of customer: ";
        cin >> income;
        if (income < 50000 || income > 100000) {
            throw IncomeException();
        }
    }

    void getcity() {
        cout << "Enter city of customer: ";
        cin >> city;
        if (city != "Pune" && city != "Mumbai") {
            throw CityException();
        }
    }

    void getroom_type() {
        cout << "Enter Customer room type: ";
        cin >> room_type;
        if (room_type != "Delux" && room_type != "Super Delux") {
            throw RoomTypeException();
        }
    }

    void display() {
        cout << "Name: " << cust_name << endl;
        cout << "ID: " << cust_id << endl;
        cout << "Age: " << age << endl;
        cout << "Income: " << income << endl;
        cout << "City: " << city << endl;
        cout << "Room Type: " << room_type << endl;
    }
};

int main() {
    Hotel h;
    char choice;

    do {
        try {
            h.accept();
            h.display();
        } catch (AgeException &e) {
            cout << "Error: " << e.what() << endl;
        } catch (IncomeException &e) {
            cout << "Error: " << e.what() << endl;
        } catch (CityException &e) {
            cout << "Error: " << e.what() << endl;
        } catch (RoomTypeException &e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "Do you want to enter another customer? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Exiting..." << endl;
    return 0;
}
