// A palindrome is a string of character that's the same forward and backward. Typically,
// punctuation, capitalization, and spaces are ignored. For example, "Poor Dan is in a droop"
// is a palindrome, as can be seen by examining the characters "poord a ni si nad roop" and
// observing that they are the same forward and backward. One way to check for a
// palindrome is to reverse the characters in the string and then compare with them the
// original-in a palindrome, the sequence will be identical. Write C++ program with functions-

// a) To print original string followed by reversed string using stack
// b) To check whether given string is palindrome or not


#include<iostream>
#include<string.h>
#include <cctype>
#define MAX 50
using namespace std;

class stack
{
    public:
     int top;
     char arr[MAX];
    void init()
    {
        top=-1;
    }
    bool isEmpty()
    {
        bool status=false;
        if(top==-1)
        {
            status=true;
        }
       
       return status;
    }

    bool isFull()
    {
        bool status = false;
        if (top == MAX-1)
        {
            status = true;
        }

        return status;
    }

     void push(char ch)
     {
        if(isFull())
        {
            cout << "\nSTACK is FULL";
        }
        else
        {
            top = top + 1;
            arr[top] = ch;
        }
     }

     char pop()
     {
        char data;
        if(isEmpty())
        {
            cout << "\nSTACK is EMPTY";
            return '\0';
        }
        else
        {
             data = arr[top];
            top = top - 1;
        }
        return data;
     }

     void print()
     {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[top];
        }
     }
};

void printOriginalReversed(string str)
{

    stack st;
    st.init();
    string reverse="";

    for (char ch : str)
    {
        st.push(ch);
    }

    while (!st.isEmpty())
    {
        reverse += st.pop();
    }

    cout<<"\n\n original string: "<<str;
    cout<<"\n reverse string: "<<reverse;
}


bool palindrome(string str)
{
   stack st1;
    st1.init();
   string reverse="";
   string filter="";

   for (char ch: str)
   {
     if(isalnum(ch))
     {
        filter += tolower(ch);
     }
   }

   for(char ch:filter)
   {
     st1.push(ch);
   }

   while(!st1.isEmpty())
   {
    reverse+=st1.pop();
   }

   cout << "\n \noriginal string: " << str;
   cout << "\n filter string: " << filter;
   cout << "\n reverse string: " << reverse;
   //    return filter == reverse;
   return filter==reverse;

 }

int main()
{
    string str;
    cout<<"\n enter the string";
    getline(cin,str);
    // Print the original and reversed string
    printOriginalReversed(str);

    // Check if the string is a palindrome
    if (palindrome(str))
    {
        cout << "\n\n The string is a palindrome." << endl;
    }
    else
    {
        cout << "\n\n The string is not a palindrome." << endl;
    }

    return 0;
}