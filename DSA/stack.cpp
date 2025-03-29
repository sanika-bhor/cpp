#include<iostream>
using namespace std;
#define MAX 20
int data[MAX], top;
void innit()
{
    top=-1;
}

int isfull()
{
    if(top==MAX-1)
    {
        return 1;
    }
    else
    {
        return(0);
    }
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return (0);
    }
}


void push()
{
    if(isfull())
    {
        cout<<"\n stack is full";
    }
    else
    {
        int x;
        cout<<"enter data: ";
        cin>>x;

        top=top+1;
        data[top]=x;
        cout << "\n data inserted: ";
    }
}

void pop()
{
    if (isempty())
    {
        cout << "\n stack is empty";
    }
    else
    {
        int x;
        x=data[top];
        top = top - 1;
        cout<<"\n data deleted: "<<x;
    }
}


void print()
{
    int i;
    cout<<"\n elements";
    for(i=top;i>=0;i--)
    {
        cout<<"\n"<<data[i];
    }
}
int main()
{
    int ch;
    innit();
    cout<<"\n1.insert";
    cout<<"\n2.delete";
    cout<<"\n3.print";
    cout<<"\n4.exit";

do{
    
    cout<<"\n\nenter choice";
    cin>>ch;


    switch(ch)
    {
        case 1:
        push();
        break;
        case 2:
        pop();
        break;

        case 3:
        print();
        break;

        case 4:
        return 0;
    }
}while(ch!=4);
 
}