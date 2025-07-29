// A fancy string is a string where no three consecutive characters are equal.
// Given a string s, delete the minimum possible number of characters from s to make it fancy.
// Return the final string after the deletion. It can be shown that the answer will always be unique.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(1)
string makeFacyString(string s)
{
    int count = 1;
    string ans = "";
    ans.push_back(s[0]);

    int n = s.length();

    for(int i=1;i<n;i++)
    {
        if(s[i]==ans.back())
        {
            count++;
            if(count < 3)
            {
                ans.push_back(s[i]);
            }
        }
        else{
            count = 1;
            ans.push_back(s[i]);
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;

    string ans = makeFacyString(s);

    cout<<ans<<endl;
    return 0;
}


//Test case
// Input: s = "leeetcode"
// Output: "leetcode"
// Explanation: "leeetcode" will be changed to "leetcode" after deleting 2 '