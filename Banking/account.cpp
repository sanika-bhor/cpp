#include <Account.h>
namespace Bank
{
    Account::Account()
    {
        accountNumber = 0;
        balance = 0.0;
        accountHolder = "";
    }

    Account::Account(int accno, double bal, string hln)
    {
        accountNumber = accno;
        balance = bal;
        accountHolder = hln;
    }

    int Account::getAccountNumber(){
        return accountNumber;
    }
    double Account::getBalance()
    {
        return balance;
    }
    string Account::getAccountHolder()
    {
        return accountHolder;
    }

    void Account::setAccountNumber(int accno){
        accountNumber=accno;
    }
    void Account::setBalance(double bal)
    {
        balance=bal;
    }
    void Account::setAccountHolder(string hln)
    {
        accountHolder=hln;
    }

    void Account::deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    void Account::withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
        else
        {
            cout << "insufficient amount" << endl;
        }
    }

    double Account::checkBalance()
    {
        cout << "\n current available balance :" << balance << endl;
        return balance;
    }

    istream &operator>>(istream &is, Account &acc)
    {
        is >> acc.accountNumber >> acc.balance >> acc.accountHolder;
        return is;
    }

    ostream &operator<<(ostream &os, Account &acc)
    {
        os << acc.accountNumber << "  " << acc.balance << "  " << acc.accountHolder;
        return os;
    }

    void Account::display()
    {
        cout << "\n Account Number : " << accountNumber;
        cout << "\n Account Holder : " << accountHolder;
        cout << "\n Balance : " << balance;
    }

    void Account::serialization(ofstream &outFile)
    {
        outFile << accountNumber << endl;
        outFile << accountHolder << endl;
        outFile << balance << endl;
    }

    void Account::deserialization(ifstream &infile)
    {
        infile >> accountNumber;
        infile.ignore();
        getline(infile, accountHolder);
        infile >> balance;
    }
}