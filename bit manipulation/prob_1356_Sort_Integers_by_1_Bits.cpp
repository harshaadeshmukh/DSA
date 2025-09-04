/* 
Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
int __builtin_popcount(int n)
{
    int count = 0;
    while(n)
    {
        if(n&1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}
*/

//time complexity : O(nlogn)  
// space complexity : O(n)
vector<int> sortIntByBits(vector<int> &arr)
{
    vector<pair<int,int>>vec;
    for(int i =0;i<arr.size();i++)
    {
        int count = __builtin_popcount (arr[i]);    
        // it is built in function that returns the total count of 1's in binary number
        // Ex : 5 (101)--> 2

        vec.push_back(make_pair(count,arr[i]));
    }

    sort(vec.begin() , vec.end());

    vector<int> result;
    for(auto it : vec)
    {
        result.push_back(it.second);
    }

    return result;
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i =0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    cout<<endl;
    vector<int> result = sortIntByBits(arr);

    for(auto it : result)
    {
        cout << it <<" ";
    }
    return 0;  
}