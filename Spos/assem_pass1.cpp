
// pass1st.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct Symbol
{
    string name;
    int addr;
};

vector<Symbol> symtab;

void addSymbol(string label, int lc)
{
    Symbol s;
    s.name = label;
    s.addr = lc;
    symtab.push_back(s);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("intermediate.txt");
    ofstream fsym("symtab.txt");

    if (!fin)
    {
        cout << "Error: input.txt not found!\n";
        return 0;
    }

    string label, opcode, op1, op2;
    int lc = 0, startAddr = 0;

    fin >> opcode;
    if (opcode == "START")
    {
        fin >> startAddr;
        lc = startAddr;
        fout << lc << "\t" << opcode << "\t" << startAddr << endl;
    }
    else
    {
        lc = 0;
    }

    while (true)
    {
        fin >> label;
        if (label == "END")
        {
            fout << lc << "\tEND" << endl;
            break;
        }

        fin >> opcode;

        if (opcode == "DS")
        {
            fin >> op1;
            addSymbol(label, lc);
            fout << lc << "\t(DL,02)\t(C," << op1 << ")\n";
            lc += stoi(op1);
        }
        else if (opcode == "DC")
        {
            fin >> op1;
            addSymbol(label, lc);
            fout << lc << "\t(DL,01)\t(C," << op1 << ")\n";
            lc++;
        }
        else if (opcode == "MOVER" || opcode == "MOVEM" ||
                 opcode == "ADD" || opcode == "SUB")
        {
            fin >> op1 >> op2;
            if (label != "**")
                addSymbol(label, lc);

            fout << lc << "\t(IS," << opcode << ")\t" << op1 << "\t" << op2 << endl;
            lc++;
        }
        else if (opcode == "STOP")
        {
            fout << lc << "\t(IS,00)" << endl;
            lc++;
        }
    }

    // Write symbol table
    for (auto &s : symtab)
    {
        fsym << s.name << "\t" << s.addr << endl;
    }

    cout << "\nPASS 1 completed successfully.\n";
    cout << "Check 'intermediate.txt' and 'symtab.txt'\n";

    fin.close();
    fout.close();
    fsym.close();
    return 0;
}

// OUTPUT :

// intermediate.txt
/*
100	START	100
100	(IS,MOVER)	AREG,	A
101	(IS,ADD)	BREG,	B
102	(DL,01)	(C,2)
103	(DL,02)	(C,5)
108	(DL,01)	(C,1)
109	END
*/

// symtab.txt
/*
A	102
B	103
C	108
*/
