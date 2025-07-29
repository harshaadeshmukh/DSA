/*
Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
    stack<int>  numberStack;
    stack<string> stringBracketStack;

    string ans = "";
    int num = 0;


    for(auto it : s)
    {

        
        //if(it >= '0' && it <= '9') or
        if(isdigit(it))
        {
            num = num * 10 + (it - '0');
        }   
        else if(it=='[')
        {
            numberStack.push(num);
            stringBracketStack.push(ans);

            num = 0;
            ans = "";
        }
        else if(it==']')
        {
            string temp = stringBracketStack.top();
            stringBracketStack.pop();

            int count = numberStack.top();
            numberStack.pop();

            while(count--)
            {
                temp = temp + ans;
            }
            ans = temp;
        }
        else 
        {
            ans.push_back(it);
        }

    }

    return ans;
}
int main()
{
    string s;
    cin >> s;

    string result = decodeString(s);
    cout << result << endl;
}