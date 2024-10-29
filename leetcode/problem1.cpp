/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

*/

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