#include"RepoManager.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace Bank
{
    // Account RepoManager::currentAccount;
    void RepoManager::saveAccountDetails()
    {
        ofstream outfile("Account.dat");
        if (outfile.is_open())
        {
            currentAccount.serialization(outfile);
            cout << "\nAccount details saved successfully";
            outfile.close();
        }
        }

        void RepoManager::getAccountDetails()
        {
            ifstream infile("Account.dat");
            if (infile.is_open())
            {
                currentAccount.deserialization(infile);
                cout << "\nAccount details get successfully";
                infile.close();
            }
        }

}