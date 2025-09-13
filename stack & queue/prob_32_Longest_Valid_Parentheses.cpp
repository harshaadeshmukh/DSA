/*
Given a string containing just the characters '(' and ')', 
return the length of the longest valid (well-formed) parentheses substring.
Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<int>st;
    int count = 0;
    st.push(-1);

    for(int i =0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            st.push(i);
        }
        else {
            st.pop();
            if(st.empty())
            {
                st.push(i);
            }
            else{
                int x = st.top();
                count = max(count , i-x);
            }
        }
    }
    cout<<"Longest Valid Parentheses : "<<count<<endl;
    cout<<"total valid parentheses : "<<count/2;

    return 0;
}