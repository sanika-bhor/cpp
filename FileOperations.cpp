/*
PROBLEM STATEMENT 4:
Write a C++ program that creates an output file,
writes information to it, closes the file, 
open it again as an input file and 
read the information from the file.
*/

#include <iostream>
#include <fstream> // For file input/output operations
#include <string>

using namespace std;

int main()
{
    string data;
    ofstream outFile("output.txt");    // Create an output file named "output.txt"

    if (!outFile) // Check if file is opened successfully
    {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    // Write some information to the file
    outFile << "This is a simple example of file handling in C++.\n";
    outFile << "We are writing data to the file and then reading it back.\n";
    outFile << "Let's see how this works.\n";

    // Close the output file after writing
    outFile.close();

    cout << "Data written to the file successfully!" << endl;

    ifstream inFile("output.txt"); // Open the file for reading
    if (!inFile) // Check if file is opened successfully
    {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    // Read data from the file and display it
    cout << "\nReading data from the file:\n";
    while (getline(inFile, data))
    {
        cout << data << endl; // Print each line of the file
    }

    // Close the input file
    inFile.close();

    return 0;
}
