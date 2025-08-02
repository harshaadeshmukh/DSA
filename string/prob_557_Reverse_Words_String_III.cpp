/*
Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseAStringIII(string s)
{
    int n = s.size();
    string ans = "";


    for(int i =0;i<n;i++)
    {
        string word = "";
        while(i < n && s[i] != ' ')
        {
            word += s[i++];
        }

        reverse(word.begin(), word.end());
        if(word.size() > 0)
        {
            ans+= " "+word;
        }
    }
    return ans.substr(1);       // Remove leading space
}

int main()
{
    string s;
    getline(cin , s);

    string ans = reverseAStringIII(s);
    cout << ans << endl;

    return 0;
}