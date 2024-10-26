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
    int min_age=20;
    int max_age=34;

    cout<<"Enter age to check eligibility for competitive exam: ";
    cin>>age;


    if(age>=min_age && age< max_age)
    {
        cout<<"\n your are eligible for competetive exam";
    }
    else
    {
        cout << "\n your are not eligible for competetive exam";
    }


}