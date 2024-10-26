/*
Your task is very simple: 
given two integers A and B, write a program to add these two numbers and output the sum.
*/


#include <iostream>
using namespace std;
int main()
{
    int n,a,b,sum;
    // taking how many times to perform addition
    cout << "enter how many time you want to add different  numbers: ";
    cin >> n;

    // taking n numbers as a input
    for (int i = 0; i < n; i++)
    {
        cout << "enter the first number: ";
        cin >> a;

        cout << "enter the second number: ";
        cin >> b;

        int sum=a+b;
        cout<<"\n addition: "<<sum<<endl;
    }
    
}