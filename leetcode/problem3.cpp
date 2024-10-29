/*
Given a string s, return the longest
palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/


#include<iostream>
#include <string>
#include<algorithm>
using namespace std;


class Solution
{
public:
    string longestPalindrome(string s)
    {
        string longest = "";
        for(int i=0; i< s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string substring = s.substr(i, j - i + 1); // Correct length
                string reversed = substring;
                reverse(reversed.begin(), reversed.end());
                if (substring == reversed && substring.size() > longest.size())
                {
                    longest = substring;
                }
            }
        }

        return longest;
    }
};

int main()
{
    Solution solution;
    string result = solution.longestPalindrome("babad");
    cout << "Longest Palindromic Substring: " << result << endl;
}