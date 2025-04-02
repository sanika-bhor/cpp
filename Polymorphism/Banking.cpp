#include <iostream>
using namespace std;
class Account
{
public:
    virtual void withdraw(int amount) = 0;
    virtual void deposite(int amount) = 0;
    virtual void displayBalance() = 0;
};

class SavingAccount : public Account
{
    private:
        double balance;
        double processingFees;
    public:
        SavingAccount(double initial)
        {
            balance=initial;
            processingFees=2;
        } 
        void withdraw(int amount) override
        {
            balance = balance-amount;
        }
        void deposite(int amount) override
        {
            balance = balance + amount;
        }
        void displayBalance() override
        {
            cout << "Balance of saving account: " <<balance<< endl;
        }
};

class CurrentAccount : public Account
{
    private:
        double balance;
        double processingFees;

    public:
        CurrentAccount(double initial)
        {
            balance = initial;
            processingFees = 15;
        }
        void withdraw(int amount) override
        {
            balance = balance - amount;
        }
        void deposite(int amount) override
        {
            balance = balance + amount;
        }
        void displayBalance() override
        {
            cout << "Balance of saving account: " << balance << endl;
        }
};

int main()
{
    Account *savingAcc = new SavingAccount(520);
    savingAcc->displayBalance();
    savingAcc->withdraw(20);
    savingAcc->deposite(200);
    savingAcc->displayBalance();

    Account *currentAcc = new CurrentAccount(77900);
    currentAcc->displayBalance();
    currentAcc->withdraw(7900);
    currentAcc->deposite(450);
    currentAcc->displayBalance();
    return 0;
}