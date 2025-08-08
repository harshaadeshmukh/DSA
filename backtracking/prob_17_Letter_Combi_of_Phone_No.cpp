/*
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(int index , string digits, string &temp , vector<string> &result, unordered_map<char , string> &mp)
{
    if(index >=digits.size())
    {
        result.push_back(temp);
        return;
    }

    char ch = digits[index];
    string str_temp = mp[ch];
    for(int i=0;i<str_temp.size();i++)
    {
        temp.push_back(str_temp[i]);
        solve(index+1,digits,temp,result,mp);
        temp.pop_back();
    }
}

vector<string> letterCombinationsProblem(string digits)
{
    if(digits.empty()){
        return {};
    }

    vector<string> result;
    string temp = "";

    unordered_map<char ,string> mp;

    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    solve(0,digits,temp,result,mp);

    return result;

}

int main()
{
    string digits;
    cin >> digits;


    vector<string> result = letterCombinationsProblem(digits);
    for(auto it : result)
    {
        cout << it << " , ";
    }

    return 0;
}