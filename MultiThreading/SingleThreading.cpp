// serial execution
#include<iostream>
using namespace std;
void display_hello()
{
    cout << "Hello, World!" <<endl;
}

void display_bye()
{
    cout << "Bye, World!" <<endl;
}

void inputName()
{
    string name;
    cout << "Enter your name: ";
    cin>>name;

    cout<<"your name is: "<<name<<endl;
}
int main()
{
    cout<<"primary thread is started"<<endl;
    display_hello();
    inputName();
    display_bye();
    cout << "primary thread is terminated"<<endl;
    return 0;
}