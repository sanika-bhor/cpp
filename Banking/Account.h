#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <fstream>
using namespace std;

namespace Bank
{
    class Account
    {
    private:
        int accountNumber;
        double balance;
        string accountHolder;

    public:
        Account();
        Account(int accno, double bal, string hln);

        int getAccountNumber();
        double getBalance();
        string getAccountHolder();

        void setAccountNumber(int accno);
        void setBalance(double bal);
        void setAccountHolder(string hln);

        void deposit(double amount);
        void withdraw(double amount);
        double checkBalance();
        
        void display();

        void serialization(ofstream &outFile);
        void deserialization(ifstream &infile);

        friend istream &operator>>(istream &is, Account &acc);
        friend ostream &operator<<(ostream &os, Account &acc);
    };
}
#endif
