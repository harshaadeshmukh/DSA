/*

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string multiplyStringwithNumber(string num1 , string num2)
{
    if(num1=="0" || num2=="0")
    {
        return "0";
    }
    
    int n = num1.size();
    int m = num2.size();

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    vector<int> result( n + m ,0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int mulNum = (num1[i] - '0') * (num2[j] - '0');

            result [ i+j ] = result[i+j] + mulNum; 


            if(result[i+j] >= 10)
            {
                result[i+j+1] += result[i+j] / 10; // Carry to the next position
                result[i+j] = result[i+j] % 10; // Keep the last digit
            }
        }
    }

    if(result.back()==0)
    {
        result.pop_back();
    }

    string ans = "";
    for(int i = result.size() - 1 ; i >= 0 ;i--)
    {
        ans.push_back(result[i] + '0');
    }

    return ans;

}
int main()
{
    string s1 , s2;
    cin >> s1;
    cin >> s2;

    string ans = multiplyStringwithNumber(s1, s2);

    cout << ans << endl;
    return 0;
}
