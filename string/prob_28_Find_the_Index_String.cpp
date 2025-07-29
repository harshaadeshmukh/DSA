// Given two strings s1 and s2, 
//return the index of the first occurrence of s2 in s1, or -1 if s2 is not part of s1.
// Example 1:
// Input: s1 = "sadbutsad", s2 = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n*m) where n is the length of s1 and m is the length of s2
// space complexity : O(1)
int longestSubstringOfFirstOccurrence(string s1 , string s2)
{
    if(s1.length() < s2.length())
    {
        cout << -1 << endl;
        return 0;
    }

    int size = s1.length() - s2.length();
    int s2Size = s2.length();
    for(int i=0;i<=size;i++)
    {
        if(s1.substr(i , s2Size ) == s2)
        {
            return i+1; // Return the index of the first occurrence (1-based index)
        }
    }
    return -1;  // If no occurrence found, return -1
}
int main()
{
    string s1 , s2;
    cin >> s1;
    cin >> s2;

    int index = longestSubstringOfFirstOccurrence(s1, s2);

    cout << index << endl;
    return 0;

}