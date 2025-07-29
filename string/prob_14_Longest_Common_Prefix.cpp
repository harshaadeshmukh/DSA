#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n*m)
// space complexity : O(1)
string longestCommonPrefix(vector<string>& str)
{

    if(str.empty()) return ""; // If the vector is empty, return an empty string

    string ans = "";
    int n = str[0].size();
    int m = str.size();
    for(int i=0;i<n;i++)
    {
        char ch = str[0][i];

        bool flag = true;
        for(int j=1;j<m;j++)
        {
            if(ch !=str[j][i])
            {
                flag = false;
                break;
            }
        }
        if(flag==false){
           break;
        }

        ans.push_back(ch);
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> str;

    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        str.push_back(s);
    }

    string ans = longestCommonPrefix(str);

    cout <<"Longest Common Prefix : "<< ans << endl;
    return 0;

}

// Appraoch:
// 1. Take the first string and iterate through its characters.
// 2. For each character, check if it is present at the same index in all other strings.
// 3. If it is, append it to the result string.
// 4. If a character does not match, break the loop and return the result string
// 5. If all characters match, return the entire first string as the common prefix.
// 6. If no characters match, return an empty string.


// Test Case 1 :
// 4
// plot
// plumber
// plain
// plastic
// Longest Common Prefix : pl
