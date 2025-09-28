/*
Example 1:
Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

Example 2:
Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.

Example 3:
Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveStringCompression(vector<char> &chars)
{
    int n = chars.size();

    int index = 0;
    for(int i=0;i<n;i++)
    {
        char ch = chars[i];

        int count =0;

        while(i < n && chars[i] == ch)
        {
            count++;
            i++;
        }

        if(count ==1)
        {
            chars[index++] = ch;
        }
        else{
            chars[index++] = ch;

            string countStr = to_string(count);
            for(char c : countStr)
            {
                chars[index++] = c;
            }
        }
        i--; // Adjust i since the outer loop will increment it
    }

    cout << "Compressed array: ";
    for(int i=0;i<index;i++)
    {
        cout << chars[i] << " ";
    }
    cout << endl;
    return index; // Return the new length of the compressed array

}

int main()
{
    int n;
    cin >> n;

    vector<char> ans(n);

    for(int i=0;i<n;i++)
    {
        cin >> ans[i];
    }

    int result = solveStringCompression(ans);

    cout << "New length of the compressed array: " << result << endl;
    return 0;
}
