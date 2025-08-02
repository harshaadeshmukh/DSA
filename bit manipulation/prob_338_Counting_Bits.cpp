//Test case for counting bits in numbers from 0 to n
/* Input: n = 2
 Output: [0,1,1]
 Explanation:
0 --> 0
1 --> 1
2 --> 10
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countBits(int n) 
{
    int count = 0;
    while(n)
    {
        if( n&1)
        {
            count++;
        }
        n = n >> 1; // Right shift to check the next bit
    }

    return count;
}
vector<int> count1Bits(int n)
{
    
    vector<int>result;

    for(int i =0;i<=n;i++)
    {
        int temp = countBits(i);

        result.push_back(temp);
    }
    return result;
}
int main()
{
    int n ;
    cin >> n;

    vector<int> ans = count1Bits(n);

    int size = ans.size();
    for(int i=0;i<size;i++)
    {
        // cout << ans[i] << " ";
        cout << i << " --> " << ans[i] << endl;

    }
}