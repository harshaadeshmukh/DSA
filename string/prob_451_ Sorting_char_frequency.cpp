#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(nlogn)
// space complexity : O(n)
string frequencySortChar(string s)
{
    unordered_map<char , int> mp;

    for(auto it : s)
    {
        mp[it]++;
    }

    priority_queue<pair<int , char>>pq;

    for(auto it : mp)
    {
        char ch = it.first;
        int count = it.second;
        pq.push({count, ch});
    }

    string ans = "";

    while(!pq.empty())
    {
        auto it = pq.top();
        char ch = it.second;
        int count = it.first;
        pq.pop();

        ans.append(count , ch);
    }

    return ans;
}

//time complexity : O(nlogn)
//space complexity : O(n)
string frequencySortChar2(string s)
{
    unordered_map<char , int> mp;

    for(auto it : s)
    {
        mp[it]++;
    }

    vector<pair<int , char>> v;

    for(auto it : mp)
    {
        char ch = it.first;
        int count = it.second;
        v.push_back({count, ch});
    }

    sort(v.begin(), v.end(), greater<pair<int, char>>());

    string ans = "";

    for(auto it : v)
    {
        char ch = it.second;
        int count = it.first;
        ans.append(count, ch);
    }

    return ans;
}
int main()
{
    string s;
    getline(cin,s);

    string s2 = frequencySortChar(s);       //by large to small frequency
    
    cout <<"Approach 1 :" << s2 << endl;

    string s3 = frequencySortChar2(s);
    cout <<"Approach 2 :" << s3 << endl;
    return 0;
}

/*
Example 1:
Input: s = "tree"
Output: "eert"
*/