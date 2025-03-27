#ifndef REPOMANAGER_H
#define REPOMANAGER_H
#include "Account.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace Bank
{
    class RepoManager
    {
    public:
        static Account currentAccount;

        static void saveAccountDetails();
        static void getAccountDetails();
    };

}
#endif