#include<iostream>
using namespace std;
class Animal
{
    public:
    virtual void sound()=0;
};

class Dog : public Animal
{
    public:
        void sound() override
        {
            cout<<"BARK....."<<endl;
        }
    };

class Lion: public Animal
{
    public:
        void sound() override
        {
            cout<<"ROAR....."<<endl;
        }
};

int main()
{
   Animal *dog=new Dog();
    dog->sound();

    Animal *lion=new Lion();
    lion->sound();
    return 0;
}