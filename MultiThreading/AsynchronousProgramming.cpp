#include<iostream>
#include<chrono>
#include<future>
#include<thread>

using namespace std;
string getProduct()
{
     this_thread::sleep_for(chrono::seconds(6));
     cout<<"getting products"<<endl;
     return "gerberra";
}

void choose()
{
    cout << "searching products" << endl;
}

void sort()
{
    cout << "sort products" << endl;
}


int main()
{
    cout<<"primary thread is start"<<endl;
    std::future<string> resultdata=std::async(launch::async, getProduct);
    string data=resultdata.get();
    cout<<data<<endl;
    cout<<"primary thread is about to terminate"<<endl;
    return 0;
}