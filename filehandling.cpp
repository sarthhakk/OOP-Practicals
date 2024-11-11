/*Implement file handling and File input output operations in C++
Create “BOOK.txt” file.
Put some text in the file created above
Develop an object-oriented program in C++ to writes data to a file, reads it back, and
displays the content in other file,Write a function in C++ to count the number of
uppercase alphabets,to count letters present in a file, to count digits present in a file, to
count white spaces present in a file, to count vowels present in a file using the file
pointer concept.*/



#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

void read(const string &filename)
{
    ifstream input(filename);
    if (!input)
    {
        cout << "Error opening file !!" << endl;
        return;
    }

    string line;
    while (getline(input, line))
    {
        cout << line << endl;
    }
    input.close();
}

void write(const string &filename)
{
    ofstream output(filename);
    if (!output)
    {
        cout << "Error opening file !!" << endl;
        return;
    }
    cout << "Enter the text to write:(type quit to exit): " << endl;
    string text;
    while (true)
    {
        getline(cin, text);
        if (text == "quit" || text == "Quit")
        {
            break;
        }
        output << text << endl;
    }
    output.close();
}

void append(const string &filename)
{
    ofstream output(filename, ios::app);
    if (!output)
    {
        cout << "Error opening file !!" << endl;
        return;
    }
    cout << "Enter the text to append:(type quit to exit): " << endl;
    string text;
    while (true)
    {
        getline(cin, text);
        if (text == "quit" || text == "Quit")
        {
            break;
        }
        output << text << endl;
    }
    output.close();
}

void count(const string &filename)
{
    ifstream input(filename);
    if (!input)
    {
        cout << "Error opening file !!" << endl;
        return;
    }
    int characterCount = 0, upperCount = 0, lowerCount = 0, vowelCount = 0, digitCount = 0, space = 0;
    char ch;
    while (input.get(ch))
    {
        if (ch)
            characterCount++;
        if (isupper(ch))
            upperCount++;
        if (islower(ch))
            lowerCount++;
        if (isdigit(ch))
            digitCount++;
        if (isspace(ch))
            space++;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowelCount++;
        }
    }
    cout << "\nCharacters: " << characterCount << endl;
    cout << "Uppercase le􀆩ers: " << upperCount << endl;
    cout << "Lowercase le􀆩ers: " << lowerCount << endl;
    cout << "Vowels: " << vowelCount << endl;
    cout << "Digits: " << digitCount << endl;
    cout << "Whitespaces: " << space << endl;
    input.close();
}

void copy(const string &sf, const string &df)
{
    ifstream src(sf);
    ofstream dest(df);
    char ch;
    while (src.get(ch))
    {
        dest.put(ch);
    }
    cout << "\nFile copied successfully." << endl;
    src.close();
    dest.close();
}

void erase(const string &filename)
{
    ofstream output(filename, ios::trunc);
    if (!output)
    {
        cout << "Error opening file !!" << endl;
        return;
    }
    cout << "File erased successfully." << endl;
    output.close();
}

void cut(const string &sf, const string &df)
{
    ifstream src(sf);
    if (!src)
    {
        cout << "Error opening source file !!" << endl;
        return;
    }

    ofstream dest(df);
    if (!dest)
    {
        cout << "Error opening destination file !!" << endl;
        src.close();
        return;
    }

    char ch;
    while (src.get(ch))
    {
        dest.put(ch);
    }
    src.close();
    dest.close();
    erase(sf); // Call the previously defined erase function

    cout << "Contents cut and pasted successfully." << endl;
}
int main()
{
    int ch;
    string filename, sourcefile, desfile;
    do
    {
        cout << "\nEnter the opera􀆟on you want to perform: " << endl;
        cout << "1. Write contents to the File" << endl;
        cout << "2. Read contents from the File" << endl;
        cout << "3. Append contents to the File" << endl;
        cout << "4. Count characters" << endl;
        cout << "5. Copy contents" << endl;
        cout << "6. Delete contents" << endl;
        cout << "7. Cut contents" << endl;
        cout << "8. Exit" << endl;
        cout << "\nPlease enter your choice: ";
        cin >> ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
            cout << "Enter filename to write to: ";
            getline(cin, filename);
            write(filename);
            break;
        case 2:
            cout << "Enter filename to read from: ";
            getline(cin, filename);
            read(filename);
            break;
        case 3:
            cout << "Enter filename to append to: ";
            getline(cin, filename);
            append(filename);
            break;
        case 4:
            cout << "Enter filename to count characters : ";
            getline(cin, filename);
            count(filename);
            break;
        case 5:
            cout << "Source file: ";
            getline(cin, sourcefile);
            cout << "Destination file: ";
            getline(cin, desfile);
            copy(sourcefile, desfile);
            break;
        case 6:
            cout << "Enter filename  to delete: ";
            getline(cin, filename);
            erase(filename);
            break;
        case 7:
            cout << "Source file: ";
            getline(cin, sourcefile);
            cout << "Destination file: ";
            getline(cin, desfile);
            cut(sourcefile, desfile);
            break;
        case 8:
            return 0;
        default:
            cout << "Enter a valid choice" << endl;
            break;
        }
        cout << endl;
    } while (ch != 8);
    return 0;
}