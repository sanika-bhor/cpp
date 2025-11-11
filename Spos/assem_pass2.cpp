// Input :
// intermediate.txt
/*
100	START	100
100	(IS,ADD)	BREG,	B
101	(DL,01)	(C,5)
102	(DL,02)	(C,1)
103	(IS,00)
104	END
*/

// symtab.txt
/*
A	100
A	101
B	102
*/

// pass2.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    ifstream fin1("intermediate.txt");
    ifstream fin2("symtab.txt");
    ofstream fout("machinecode.txt");

    if (!fin1 || !fin2)
    {
        cout << "Error: intermediate.txt or symtab.txt not found!\n";
        return 0;
    }

    map<string, int> symtab;
    string sym;
    int addr;

    // --- Load symbol table ---
    while (fin2 >> sym >> addr)
    {
        symtab[sym] = addr;
    }

    string line;
    while (getline(fin1, line))
    {
        // Skip empty lines
        if (line.empty())
            continue;

        // Print directives as is
        if (line.find("START") != string::npos || line.find("END") != string::npos)
        {
            fout << line << endl;
            continue;
        }

        // Declarative statements (DL)
        if (line.find("(DL") != string::npos)
        {
            fout << line << endl;
            continue;
        }

        // --- Replace labels with their addresses ---
        for (auto &entry : symtab)
        {
            size_t pos = line.find(entry.first);
            if (pos != string::npos)
            {
                line.replace(pos, entry.first.length(), to_string(entry.second));
            }
        }

        fout << line << endl;
    }

    cout << "\nPASS 2 completed successfully.\n";
    cout << "Check 'machinecode.txt' for final machine code.\n";

    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}

// OUTPUT :

// machinecode.txt
/*
100	START	100
100	(IS,101DD)	102REG,	B
101	(DL,01)	(C,5)
102	(DL,02)	(C,1)
103	(IS,00)
104	END
*/