#include<iostream>
#include<thread>
#include<chrono>
#include<memory>
#include<future>

using namespace std;

class View
{
    public:
        virtual void rendering(shared_future<string> data)=0;
        virtual ~View()
        {
            cout << "view destructor" << endl;
        }
};

class FrontView:public View{
    public:
    void rendering(shared_future<string> data) override
    {
        thread([data](){
            string result=data.get();
            cout << "[frontview]" <<result<<endl;
        }).detach();
    }
};

class SideView : public View
{
public:
    void rendering(shared_future<string> data) override
    {
        thread([data]()
        {
            string result=data.get();
            cout << "[sideview]" <<result<< endl; 
        }).detach();
    }
};

class TopView : public View
{
public:
    void rendering(shared_future<string> data) override
    {
        thread([data]()
        {
            string result=data.get();
            cout << "[topview]" << result<<endl; 
        }).detach();
    }
} ;

class dataProvider
{
    public:
        shared_future<string> providedataAsync()
        {
            promise<string> data;
            shared_future<string> futuredata=data.get_future();

            thread([promise=move(data)]() mutable{
                this_thread::sleep_for(chrono::seconds(1));
                promise.set_value("rendering data");
            }).detach();

            return futuredata;
        }
};
int main()
{
    // Create a shared pointer to a function
    dataProvider producer;
    auto sharedfuture=producer.providedataAsync();

    FrontView fv;
    SideView sv;
    TopView tv;

    fv.rendering(sharedfuture);
    cout<<endl;
    sv.rendering(sharedfuture);
    cout << endl;
    tv.rendering(sharedfuture);
    cout << endl;

    this_thread::sleep_for(chrono::seconds(10));
    return 0;
}