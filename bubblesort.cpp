/*Develop an object-oriented program in C++ to Perform bubble sort operation using the template for
integer and float data type*/




#include <iostream>
using namespace std;
template <typename T>
class BubbleSort
{
public:
    void bubble_sort(T arr[50], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display(T arr[50], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    BubbleSort<int> s1;
    BubbleSort<double> s2;
    int arr[50], size;
    double arr1[50];
    int choice;
    do
    {
        cout << "Choose operation: " << endl;
        cout << "1. Integer Array\n2. Double Array\n3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number of elements in the integer array: " << endl;
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                cout << "Enter element" << i + 1 << ":" << endl;
                cin >> arr[i];
            }
            cout << "\nArray before sorting: ";
            s1.display(arr, size);
            cout << "\nArray after sorting: ";
            s1.bubble_sort(arr, size);
            s1.display(arr, size);
            break;
        case 2:
            cout << "Enter the number of elements in the decimal array: " << endl;
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                cout << "Enter element" << i + 1 << ":" << endl;
                cin >> arr1[i];
            }
            cout << "\nArray before sorting: ";
            s2.display(arr1, size);
            s2.bubble_sort(arr1, size);
            cout << "\nArray after sorting: ";
            s2.display(arr1, size);
            break;
        case 3:
            return 0;
        default:
            break;
        }
    } while (choice != 3);
}