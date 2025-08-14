/*
Example 1:
Input: "babad"
Output: "bab" or "aba"
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
string longestPalindromeSubstring(string s)
{
    int start = 0;
    int end = INT_MIN;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(s, i, j))
            {
                int value = j-i+1;
                if(value > end)
                {
                    end = value;
                    start = i;
                }                
            }
        }
    }
    return s.substr(start, end);
}
int main()
{
    string s;
    cin >> s;

    string result = longestPalindromeSubstring(s);

    cout << result << endl;
    return 0;
}