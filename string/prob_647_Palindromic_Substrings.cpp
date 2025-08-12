/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Demo{

    private:
    bool isCheck(string &s ,int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public :
    // only problem is that time complexity is of O(n^3)
    //]pace complexity is O(1) 
    int countSubstringCode1(string s)
    {
        int n = s.size();
        int count = 0;

        for(int i =0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isCheck(s,i,j))
                {
                    count++;
                }
            }
        }

        return count;
    }

    // time complexity is O(n^2)
    // space complexity is O(1)
    int countSubstringCode2(string &s)
    {
        int n = s.size();
        int count = 0;

        for(int i = 0;i<n;i++)
        {
            int left = i;
            int right = i;
            while(left >=0 && right < n && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }
        }

        for(int i=0;i<n-1;i++)
        {
            int left = i;
            int right = i+1;
            while(left >=0 && right < n && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }

};

int main()
{
    string s;
    cin >> s;

    Demo d;

    cout << d.countSubstringCode1(s) << endl;

    cout<< d.countSubstringCode2(s);

    return 0;

    

}