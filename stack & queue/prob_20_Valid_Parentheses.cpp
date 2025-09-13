// In this code we will check if the given parentheses are valid or not.
//Examples of valid parentheses: "()", "()[]{}", "{[]}"
//Examples of invalid parentheses: "(]", "([)]", "((()"

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
int main()
{
    string s;
    cin >> s;

    stack<char> st;

    for(int i =0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
        }
        else{
            if(st.empty())
            {
                cout<<"Invalid"<<endl;
                return 0;
            }
            
            char ch = st.top();
            st.pop();
            if((s[i]==')' && ch!='(') || (s[i]=='}' && ch!='{') || (s[i]==']' && ch!='['))
            {
                cout<<"Invalid"<<endl;
                return 0;
            }
        }
    }

    if(st.empty())  {
        cout<<"Valid"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
    return 0;
}