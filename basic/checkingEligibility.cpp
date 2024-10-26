/*
Chef wants to appear in a competitive exam. 
To take the exam, there are following requirements: 
        Minimum age limit is X (i.e. Age should be greater than or equal to X).
        Age should be strictly less than Y. 
        Chef's current Age is A. 
Find whether he is currently eligible to take the exam or not.
*/


#include<iostream>
using namespace std;

int main()
{
    int age;
    int x=20;  //minimun age
    int y=34;   //maximum age

    // Chef current age
    cout<<"Enter age to check eligibility for competitive exam: ";
    cin>>age;


    if(age>=x && age< y)
    {
        cout<<"\n your are eligible for competetive exam";
    }
    else
    {
        cout << "\n your are not eligible for competetive exam";
    }


}