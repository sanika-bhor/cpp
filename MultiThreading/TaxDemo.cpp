#include<iostream>
#include<thread>
#include<future>
#include<chrono>

using namespace std;

void processSalary(promise<int> & data)
{
    this_thread::sleep_for(chrono::seconds(5));
    int salary;
    cout<<"enter your salary: ";
    cin>>salary;
    data.set_value(520009);
}

void payIncomeTax(future<int> data)
{
    cout<<"paying income tax: "<<endl;
    int salary=data.get();
    if(salary<600000)
    {
        cout<<"no tax"<<endl;
    }
    else
    {
    int result=salary*(0.03);
    cout<<"total income tax have to paid: "<<result<<endl;
    }
}

int main()
{
    cout<<"primary thread is started.."<<endl;
    promise<int> data;
    future<int> data_future=data.get_future();

    thread tProcessSalary(processSalary,ref(data));
    thread tpayIncomeTax(payIncomeTax,move(data_future));

    tProcessSalary.join();
    tpayIncomeTax.join();

    cout<< "primary thread is about to terminate.." << endl;
}