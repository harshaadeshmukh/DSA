#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(26)
// space complexity : O(1)
bool isAnagram(string s1 , string s2)
{
    int n = s1.length();
    int m = s2.length();

    if(n!=m)
    {
        return false;
    }

    vector<int> freq(26,0);

    for(int i=0;i<n;i++)
    {
        // Increment frequency for the character in s1
        freq[s1[i] - 'a']++;

        // Decrement frequency for the character in s2
        freq[s2[i] - 'a']--;
    }

    for(int i=0;i<26;i++)       //why 26 - becuase there are 26 lowercase letters
    {
        // If any frequency is not zero, then they are not anagrams
        if(freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}

//time complexity : O(nlogn)
//space complexity : O(n)
bool isAnagram2(string s1 , string s2)
{
    int n = s1.length();
    int m = s2.length();

    if(n!=m)
    {
        return false;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1==s2;  // If sorted strings are equal, then they are anagrams otherwise not
}
int main()
{
    string s1 , s2;
    cin >> s1;
    cin >> s2;

    bool isAnagramString = isAnagram(s1,s2);

    if(isAnagramString)
    {
        cout << "Approach 1 :- Yes, they are anagrams." << endl;
    }
    else
    {
        cout << "Approach 1 :-No, they are not anagrams." << endl;
    }

    bool isAnagramString2 = isAnagram2(s1,s2);

    if(isAnagramString2)
    {
        cout << "Approach 2 :- Yes, they are anagrams." << endl;
    }
    else
    {
        cout << "Approach 2 :- No, they are not anagrams." << endl;
    }

    return 0;

}