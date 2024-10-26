#include <iostream>
using namespace std;

class Solution
{
private:
    int target;
    int output[2];
    int input[10];
    int n;
    int flag;

public:
    void twoSum()
    {
        flag=0;

        cout << "enter how many elemnts int the list: ";
        cin >> n;

        cout << "enter target element: ";
        cin >> target;

        cout << "enter " << n << " elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }

         for (int i = 0; i < n; i++)
        {
            int num = input[i];

            for (int j = 1; j < n; j++)
            {
                int sum = num + input[j];
                if (sum == target)
                {
                    output[0] = i;
                    output[1] = j;
                    flag = 1;
                    break;
                }
              
            }
            if(flag==1)
            {
                break;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            cout <<"\t"<< output[i];
        }
    }
};

int main()
{
    Solution s1;
    s1.twoSum();
}