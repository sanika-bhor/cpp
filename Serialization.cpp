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
        string AccountHolder;

    public:
        Account()
        {
            accountNumber = 0;
            balance = 0.0;
            AccountHolder = "";
        }

        Account(int accno, double bal, string hln)
        {
            accountNumber = accno;
            balance = bal;
            AccountHolder = hln;
        }

        void deposit(double amount)
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

        void withdraw(double amount)
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

        double checkBalance()
        {
            cout << "\n current available balance :" << balance << endl;
            return balance;
        }

        friend istream &operator>>(istream &is, Account &acc)
        {
            is >> acc.accountNumber >> acc.balance >> acc.AccountHolder;
            return is;
        }

        friend ostream &operator<<(ostream &os, Account &acc)
        {
            os << acc.accountNumber << "  " << acc.balance << "  " << acc.AccountHolder;
            return os;
        }

        void display()
        {
            cout << "\n Account Number : " << accountNumber;
            cout << "\n Account Holder : " << AccountHolder;
            cout << "\n Balance : " << balance;
        }

        void serialization(ofstream &outFile)
        {
            outFile << accountNumber << endl;
            outFile << AccountHolder << endl;
            outFile << balance << endl;
        }

        void deserialization(ifstream &infile)
        {
            infile >> accountNumber;
            infile.ignore();
            getline(infile, AccountHolder);
            infile >> balance;
        }
    };

    class RepoManager
    {
    public:
        static Account currentAccount;

        static void saveAccountDetails()
        {
            ofstream outfile("Account.dat");
            if (outfile.is_open())
            {
                currentAccount.serialization(outfile);
                cout << "\nAccount details saved successfully";
                outfile.close();
            }
        }

        static void getAccountDetails()
        {
            ifstream infile("Account.dat");
            if (infile.is_open())
            {
                currentAccount.deserialization(infile);
                cout << "\nAccount details get successfully";
                infile.close();
            }
        }
    };

    Account RepoManager::currentAccount(78, 250.1, "sanika");
    void displayMenu()
    {
        cout << "\n******OPERATION*********";
        cout << "\n1. check Balance";
        cout << "\n2. Withdraw Money";
        cout << "\n3. Deposit Money";
        cout << "\n4. Display Customer details";
        cout << "\n5. Serialize your Data";
        cout << "\n6.  Deserialize your Data";
        cout << "\n7. Exit";
    }

}
using namespace Bank;
int main()
{
    double amount;
    displayMenu();
    int choice;

    do
    {
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            RepoManager::getAccountDetails();
            RepoManager::currentAccount.checkBalance();
            break;

        case 2:
            RepoManager::getAccountDetails();
            cout << "\nenter amount to withdraw: ";
            cin >> amount;
            RepoManager::currentAccount.withdraw(amount);
            RepoManager::saveAccountDetails();

            break;

        case 3:
            RepoManager::getAccountDetails();
            cout << "\nenter amount to deposite: ";
            cin >> amount;
            RepoManager::currentAccount.deposit(amount);
            RepoManager::saveAccountDetails();
            break;

        case 4:
            cout << "\nAccount holder Details: ";
            RepoManager::currentAccount.display();
            break;

        case 5:
            RepoManager::saveAccountDetails();
            break;

        case 6:
            RepoManager::getAccountDetails();
            break;

        case 7:
            cout << "\nThank you ";
            break;

        default:
            break;
        }
    } while (choice != 7);

    return 0;
}