#include <iostream>
using namespace std;
int main()
{
    int matrix[3][3];
    int transpose[3][3];

    cout << "enter the matrix elements for 3 * 3 matrix\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "your matrix elements\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "your transpose matrix elements\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[i][j]=matrix[j][i];
            cout << transpose[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}