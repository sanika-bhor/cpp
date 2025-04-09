#include<iostream>
#include<future>
#include<chrono>
#include<thread>
using namespace std;

void producer(promise<int> & data)
{
    //producer produce data
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"Producor is processing....."<<endl;
    data.set_value(56);
}

void consumer(future<int> data)
{
    //consumer consume data
    cout<<"Consumer is processing....."<<endl;
    int result=data.get();
    cout<<"Result: "<<result<<endl;
}
int main()
{
    cout<<"main thread is started.."<<endl;
    promise<int> data;
    future<int> futuredata=data.get_future();

    thread producerThread(producer,ref(data));
    thread consumerThread(consumer,move(futuredata));

    producerThread.join();
    consumerThread.join();

    cout<<"main thread is about to terminate.."<<endl;
}