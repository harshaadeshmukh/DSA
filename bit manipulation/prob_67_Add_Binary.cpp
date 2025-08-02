/*
Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string addBinaryString(string a, string b)
{
    string result = "";

    int n = a.size()-1;
    int m = b.size()-1;
    int carry = 0;

    while(n >= 0 || m >= 0 || carry)
    {
        if(n >=0)
        {
            carry += a[n--] - '0';
        }
        if(m >= 0)
        {
            carry += b[m--] - '0';
        }

        result +=(carry %2) + '0';

        carry /= 2; 
    }
    reverse(result.begin(), result.end());
    return result;

}
int main()
{
    string s1;
    string s2;

    cin >> s1 >> s2;

    string ans = addBinaryString(s1, s2);

    cout << ans << endl;
    return 0;
}