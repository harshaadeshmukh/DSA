/*
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0
Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
Input: s = "loveleetcode"
Output: 2
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    vector<int> ans(26,0);

    // so basically it prints the index of an unique characters 
    for(int i=0;i<s.length();i++)
    {
        ans[s[i] - 'a']++;
    }

    int index = -1;
    for(int i=0;i<s.length();i++)
    {
        if(ans[s[i] - 'a'] == 1)
        {
            index = i;
            break;
        }
    }
    cout << "First unique character index: " << index << endl;

    // now if i want to print number of unique characters and print the characters
    int uniqueCount = 0;
    for(int i=0;i<26;i++)
    {
        if(ans[i] == 1)
        {
            uniqueCount++;
            cout << char(i + 'a') << " ";
        }
    }
    cout << endl;
    cout << "Number of unique characters: " << uniqueCount << endl;

    return 0;
}