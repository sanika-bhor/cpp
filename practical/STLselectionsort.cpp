/*
PROBLEM STATEMENT 5:
Write a function template for selection sort that inputs, sorts and outputs an integer array and
a float array.
*/

#include <iostream>
using namespace std;

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int size)
{
    int k;
    int temp;
    for (int i = 0; i < size; i++)
    {
        k = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }

        if (k != i)
        {
            temp = arr[k];
            arr[k] = arr[i];
            arr[i] = temp;
        }
    }
}

// Function template to display an array
template <typename T>
void displayArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Example with an integer array
    int intArray[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    cout << "Original integer array: ";
    displayArray(intArray, intSize);

    selectionSort(intArray, intSize);
    cout << "Sorted integer array: ";
    displayArray(intArray, intSize);

    // Example with a float array
    float floatArray[] = {64.5, 25.3, 12.7, 22.9, 11.1};
    int floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

    cout << "Original float array: ";
    displayArray(floatArray, floatSize);

    selectionSort(floatArray, floatSize);
    cout << "Sorted float array: ";
    displayArray(floatArray, floatSize);

    return 0;
}
