//Test Case 1 :
// Input: s = "abcabcbb"
// Output: 3
// and the longest substring is "abc".

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(1)
// Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstringwithInt(string s)
{
    unordered_set<char> st;

    int left = 0;
    int maxSum = 0;
    int n = s.length();
    for(int right = 0; right <n; right++)
    {
        while(st.count(s[right]))
        {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);
        maxSum = max(maxSum, right - left + 1);
    }
    return maxSum;
}

// time complexity : O(n)
// space complexity : O(n)
// Given a string s, find the longest substring without repeating characters.
// Return the substring itself.
string lengthOfLongestSubstring(string s)
{
    int left = 0;
    int maxSum = 0;
    int startIndex = 0;

    unordered_set<char>st;
    int n = s.length();
     for(int right = 0; right < n; right++)
    {
        while(st.count(s[right]))
        {
            st.erase(s[left]);
            left++;
        }

        st.insert(s[right]);

        if(right - left +1 > maxSum)
        {
            maxSum = right - left + 1;
            startIndex = left;
        }
        // maxSum = max(maxSum, right - left + 1);
    }
    return s.substr(startIndex, maxSum);
}

int main()
{
    string s;
    cin >> s;

    int result = lengthOfLongestSubstringwithInt(s);

    string ans = lengthOfLongestSubstring(s);

    cout << result << endl;
    cout << ans << endl;

    return 0;

}
