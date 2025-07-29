#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(1)
string reverseWordString(string s)
{
    reverse(s.begin() , s.end());

    string ans = "";
    int n = s.size();

    for(int i=0;i<n;i++)
    {
        string word = "";
        while(i < n && s[i]!= ' ')
        {
            word.push_back(s[i]);
            i++;
        }
        reverse(word.begin() , word.end());
        if(word.size() > 0)
        {
            ans+=" "+word;
        }

    }
    return ans.substr(1); // Remove leading space
} 

// time complexity : O(n^2)
// space complexity : O(n)
string reverseWordStringUsingSTL(string s)
{
    string ans = "";
    istringstream iss(s);

    while(iss >> s)
    {
        ans = s + " " + ans;
    }

    return ans;
}


int main()
{
    string s;
    getline(cin ,s);

    string ans = reverseWordString(s);
    cout << "Approach 1:  " << ans << endl;


    string ans2 = reverseWordStringUsingSTL(s);
    cout << "Approach 2:  " << ans2 << endl;
    return 0;
}

//Approach:
// 1. Reverse the entire string.
// 2. Iterate through the string and reverse each word. 
// 3. Use a space to separate words.
// 4. Return the final string with words in reverse order.
// 5. Alternatively, use STL to split the string into words and reverse them while concatenating.


//TestCases:
// I     love v   coding
// Approach 1:  coding v love I
// Approach 2:  coding v love I
