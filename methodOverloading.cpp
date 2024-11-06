/* 
write a c++ program to implement method overloading have class name as 'mathEngine' perform addition,subtraction by overloading add() & sub() 
also implement constructor overloading. create dynamic memory allocation.
-------------------------------------------------------------------
    class : mathEngine
 function : add(n1,n2)
            add(n1,n2,n3)
            sub(n1,n2)
            sub(n1,n2,n3)
constructor: default
             parameterized
*/
#include<iostream>
using namespace std;

class mathEngine
{
    
    public:
    // constructor overloading
    // default constructor
    mathEngine()
    {
        cout << "Math Engine is created" << endl;
    }
    // parameterized constructor
    mathEngine(int num1, int num2)
    {
        cout << "\n\nMath Engine is created with two numbers" << endl;
    }
    // method overloadding:add()
    int add(int num1, int num2)
    {
        return num1+num2;
    }
    int add(int num1, int num2, int num3)
    {
        return num1+num2+num3;
    }

    // method overloadding:sub()
     int sub(int num1, int num2)
    {
        return num1-num2;
    }
    int sub(int num1, int num2, int num3)
    {
        return num1-num2-num3;
    }
};
int main()
{
    // dynamic memory allocation:
    // it create object on heap memory and stores the address of stack memory
    mathEngine *ptrMathEngine=new mathEngine();
    // add()
    int result1 = ptrMathEngine->add(20, 10);
    cout<<"result of add function having 2 parameters: "<<result1;
    int result2 = ptrMathEngine->add(10, 20, 30);
    cout << "\nresult of add function having 2 parameters: " << result2;

     // sub()
    int subResult1 = ptrMathEngine->sub(20, 10);
    cout<<"\nresult of add function having 2 parameters: "<<subResult1;
    int subResult2 = ptrMathEngine->sub(10, 20, 30);
    cout << "\nresult of add function having 2 parameters: " << subResult2;

    mathEngine *ptrMathEngine2 = new mathEngine(10, 20);
   int result3= ptrMathEngine2->add(56, 78);
    cout << "result of add function having 2 parameters: " << result3;

    int result4=ptrMathEngine2->add(25, 2, 96);
    cout << "\nresult of add function having 2 parameters: " << result4;

    return 0;
}