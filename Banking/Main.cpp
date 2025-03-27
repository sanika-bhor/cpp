#include <iostream>
#include "RepoManager.h"
#include "UiManager.h"
#include <fstream>
using namespace Bank;

Account RepoManager::currentAccount(15,250,"sanika");
int main()
{
    double amount;

    UiManager::displayMenu();
    int choice;
    string name;

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
            cout<<"\nEnter the Name of the User: ";
            cin>>name;
            RepoManager::getAccountDetails();
            RepoManager::currentAccount.setAccountHolder(name);
            RepoManager::saveAccountDetails();
            break;

        case 6:
            cout << "\nThank you ";
            break;

        default:
            break;
        }
    } while (choice != 6);

    return 0;
}

// g++ Account.cpp UiManager.cpp RepoManager.cpp main.cpp - o main.exe
// main.exe