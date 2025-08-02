/*
Input: s = "abcdefghij", k = 3
Output: "cbadefihgj"

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//time complexity : O(n)
//space complexity : O(1)
string reverseAStringByK(string s, int k)
{
    int n = s.size();
    for(int i=0;i<n;i+=2*k)
    {
        int left = i;
        int right = min(i + k - 1, n - 1);
        while(left <=right)
        {
            swap(s[left++], s[right--]);
        }
        if(right==n-1)
        {
            break;
        }
    }
    return s;
}
int main()
{
    string s;
    int k;

    cin >> s;
    cin >> k;

    string ans = reverseAStringByK(s,k);
    cout << ans << endl;
    return 0;
}