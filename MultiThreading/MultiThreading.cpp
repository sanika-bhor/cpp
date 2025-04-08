#include <iostream>
#include <thread>
#include<chrono>
using namespace std;
void display_hello()
{
    int i=0;
    while (i<5)
    {
        cout << "Hello, World! from thread 1" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        i++;
    }
}

void display_bye()
{
    int i = 0;
    while (i < 5)
    {
        cout << "Bye, World! from thread 2" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        i++;
    }
}

int main()
{
    cout<<"primary thread is started"<<endl;
    thread t1(display_hello);
    t1.join();
    thread t2(display_bye);
    t2.join();
    cout << "primary thread is terminated" << endl;

    return 0;
}