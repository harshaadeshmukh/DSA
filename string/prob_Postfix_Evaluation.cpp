/*
Example 1:
Input: arr[] = ["2", "3", "1", "*", "+", "9", "-"]
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.

Example 2:
Input: arr[] = ["2", "3", "^", "1", "+"]
Output: 9
Explanation: If the expression is converted into an infix expression, it will be 2 ^ 3 + 1 = 8 + 1 = 9.

PRoblem: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solveUsingPostfix(string s)
{
    stack<int>st;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int c = 0;
            if(s[i]=='+')
            {
                c = a+b;
            }
            else if(s[i]=='-')
            {
                c = a-b;
            }
            else if(s[i]=='*')
            {
                c = a*b;
            }
            else if(s[i]=='/')
            {
                c = a/b;
            }
            else if(s[i]=='^')
            {
                c = pow(a,b);
            }
            st.push(c);
        }
        else{
            st.push(s[i]-'0');  // converting char to int
        }
    }

    return st.top();
} 
int main()
{
    string s;
    cin >> s;

    int result = solveUsingPostfix(s);

    cout << result << endl;
    return 0;
}