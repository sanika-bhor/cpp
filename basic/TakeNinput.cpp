/*
Write a program that takes a number N as the input, and prints it to the output.
*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    // taking how many number user want to get and display
    cout<<"enter no of inputes do you want to take: ";
    cin>>n;

    int number[n];
    // taking n numbers as a input
    for(int i=0;i<n;i++)
    {
        cout<<"enter the number: ";
        cin>>number[i];
    }
    // printing numbers
    for (int i = 0; i < n; i++)
    {
        cout << "\n "<<number[i];
    }
}