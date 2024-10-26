/*
Chef and Chefina are playing with dice. 
In one turn, both of them roll their dice at once. 
They consider a turn to be good if the sum of the numbers on their dice is greater than 6. 
Given that in a particular turn Chef and Chefina got X and Y on their respective dice, 
find whether the turn was good.
*/

#include<iostream>
using namespace std;
int main()
{
    int turn;
    int x, y;
    cout<<"\n Enter numbers of turns: ";
    cin>>turn;

    for (int i = turn; i > 0; i--)
    {
        cout<<"Enter chef dice count: ";
        cin>>x;
        cout<<"Enter chefina dice count: ";
        cin>>y;

        int sum=x+y;
        if(sum>=6)
        {
            cout<<"\n YES, the turn is good";
        }
        else
        {
            cout<<"\n NO, turn is not good";
        }
    }
}