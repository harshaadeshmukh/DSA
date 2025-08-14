/*
Example 1:
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:
Input: tiles = "AAABBC"
Output: 188

Example 3:
Input: tiles = "V"
Output: 1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void solve(string &s , string &curr , unordered_set<string> &st , vector<bool> &visited)
{
    if(!curr.empty())
    {
        st.insert(curr);
    }

    for(int i =0; i < s.length(); i++)
    {
        if(visited[i])
        {
            continue;
        }

        curr.push_back(s[i]);
        visited[i] = true;
        solve(s, curr , st , visited);
        curr.pop_back();
        visited[i] = false;
    }
}
vector<string> findTotalNumOfTitles(string s)
{
  
    unordered_set<string> st;
    vector<bool> visited(s.length() , false);
    string curr = "";

    solve(s, curr , st , visited);

    return vector<string>(st.begin() , st.end());
}
int main()
{
    string s;
    cin >> s;

    vector<string> result = findTotalNumOfTitles(s);
    sort(result.begin() , result.end());
    for(auto &it : result)
    {
        cout << it <<" ";
    }
    cout<<endl<<result.size() << endl;

    return 0;
}