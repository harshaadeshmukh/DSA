/*
Example 1:
Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333". "777" is the largest, so we return "777".

Example 2:
Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.

Example 3:
Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string ans;
    int count = 1;
    for(int i= 1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
        {
            count++;
            if (count == 3){
                ans = max(ans , string(3,s[i-1]));
            }
        }
        else{
            count = 1;
        }
    }

    cout << ans << endl;
    return 0;
}