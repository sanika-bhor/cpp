// Input :
// input.txt
/*
START 100
MOVER AREG, A
ADD BREG, B
A DC 5
B DS 1
STOP
END
*/

// Combined Pass1&2 Assembler :
// Combined_pass.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

// ===== PASS 1 =====
void pass1()
{
    ifstream fin("input.txt");
    ofstream fout("intermediate.txt");
    ofstream fsym("symtab.txt");

    if (!fin)
    {
        cout << "Error: input.txt not found!\n";
        return;
    }

    map<string, string> MOT = {
        {"STOP", "(IS,00)"}, {"ADD", "(IS,01)"}, {"SUB", "(IS,02)"}, {"MULT", "(IS,03)"}, {"MOVER", "(IS,04)"}, {"MOVEM", "(IS,05)"}, {"COMP", "(IS,06)"}, {"BC", "(IS,07)"}, {"DIV", "(IS,08)"}, {"READ", "(IS,09)"}, {"PRINT", "(IS,10)"}};

    map<string, string> REG = {
        {"AREG", "1"}, {"BREG", "2"}, {"CREG", "3"}, {"DREG", "4"}};

    map<string, string> DL = {{"DC", "(DL,01)"}, {"DS", "(DL,02)"}};

    string label, opcode, operand1, operand2;
    int locctr = 0;

    fout << "LC\tIC" << endl;

    while (fin >> label)
    {
        if (label == "START")
        {
            fin >> locctr;
            fout << locctr << "\t" << "START\t" << locctr << endl;
            continue;
        }

        // If label not instruction, it is a symbol
        if (MOT.find(label) == MOT.end() && DL.find(label) == DL.end() && label != "END")
        {
            fsym << label << "\t" << locctr << endl;
            fin >> opcode;
        }
        else
        {
            opcode = label;
        }

        if (opcode == "END")
        {
            fout << locctr << "\t" << "END" << endl;
            break;
        }

        if (MOT.find(opcode) != MOT.end())
        {
            fin >> operand1 >> operand2;
            fout << locctr << "\t" << MOT[opcode] << "\t" << operand1 << "\t" << operand2 << endl;
            locctr++;
        }
        else if (DL.find(opcode) != DL.end())
        {
            fin >> operand1;
            fout << locctr << "\t" << DL[opcode] << "\t(C," << operand1 << ")" << endl;
            locctr++;
        }
    }

    fin.close();
    fout.close();
    fsym.close();

    cout << "PASS 1 completed successfully.\n";
    cout << "Generated: intermediate.txt and symtab.txt\n";
}

// ===== PASS 2 =====
void pass2()
{
    ifstream fin1("intermediate.txt");
    ifstream fin2("symtab.txt");
    ofstream fout("machinecode.txt");

    if (!fin1 || !fin2)
    {
        cout << "Error: intermediate.txt or symtab.txt not found!\n";
        return;
    }

    map<string, int> symtab;
    string sym;
    int addr;

    while (fin2 >> sym >> addr)
        symtab[sym] = addr;

    string line;
    while (getline(fin1, line))
    {
        if (line.empty())
            continue;

        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        if (line.find("START") != string::npos || line.find("END") != string::npos)
        {
            fout << line << endl;
            continue;
        }

        if (line.find("(DL") != string::npos)
        {
            fout << line << endl;
            continue;
        }

        // Replace symbols with addresses
        for (auto &entry : symtab)
        {
            stringstream ss(line);
            string word, result;
            bool replaced = false;

            while (ss >> word)
            {
                if (word == entry.first)
                {
                    word = to_string(entry.second);
                    replaced = true;
                }
                result += word + " ";
            }

            if (replaced)
            {
                line = result;
                break;
            }
        }

        fout << line << endl;
    }

    fin1.close();
    fin2.close();
    fout.close();

    cout << "PASS 2 completed successfully.\n";
    cout << "Generated: machinecode.txt\n";
}

// ===== MAIN =====
int main()
{
    cout << "===== TWO PASS ASSEMBLER =====\n";
    pass1();
    pass2();
    cout << "\nAssembler execution completed.\n";
    return 0;
}

// OUTPUT :
// intermediate.txt
/*
LC	IC
100	START	100
100	(IS,04)	AREG,	A
101	(IS,01)	BREG,	B
102	(DL,01)	(C,5)
103	(DL,02)	(C,1)
104	(IS,00)	END	B
*/

// symtab.txt
/*
A	102
B	103
*/

// machinecode.txt
/*
LC	IC
100	START	100
100 (IS,04) AREG, 102
101 (IS,01) BREG, 103
102	(DL,01)	(C,5)
103	(DL,02)	(C,1)
104	(IS,00)	END	B
*/