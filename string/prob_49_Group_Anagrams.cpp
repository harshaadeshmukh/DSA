#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// time complexity : O(n * k log k) where n is the number of words and k is the maximum length of a word
// space complexity : O(n * k)
vector<vector<string>> groupAnagramsWords(vector<string> &words){
       
    unordered_map<string , vector<string>> mp;

    for(auto it : words)
    {
        string temp = it;
        sort(temp.begin() , temp.end());

        mp[temp].push_back(it);
    }

    vector<vector<string>> ans;
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;


}
int main()
{
    int n;
    cin >> n;

    vector<string> words(n);
    for(int i=0;i<n;i++)
    {
        string temp ;
        cin >> temp;
        words[i] = temp;
    }
    vector<vector<string>> ans = groupAnagramsWords(words);
    
    cout<<endl;
    for(auto it : ans)
    {
       cout<< "[ ";
       for(auto str : it)
         {
              cout << str << " ";
        }
         cout << "] ";

    }
    return 0;
}