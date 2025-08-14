/*
Input: s = "abccbaacz"
Output: "c"
Explanation:
The letter 'a' appears on the indexes 0, 5 and 6.
The letter 'b' appears on the indexes 1 and 4.
The letter 'c' appears on the indexes 2, 3 and 7.
The letter 'z' appears on the index 8.
The letter 'c' is the first letter to appear twice, because out of all the letters the index of its second occurrence is the smallest.
Example 2:

Input: s = "abcdd"
Output: "d"
Explanation:
The only letter that appears twice is 'd' so we return 'd'.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> ans(26, 0); 

    for(int i = 0; i < s.length(); i++)
    {
        ans[s[i] - 'a']++;
        if(ans[s[i] - 'a'] == 2)
        {
            cout << s[i] << endl;
            return 0;
        }
    }

    cout << "No character appears twice." << endl;
    return 0;

}
