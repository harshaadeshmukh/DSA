#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count1Bits(int n)
{
    int count = 0;

    while(n)
    {
        if(n&1)
        {
            count++;
        }
        n = n>> 1;
    }
}
int main()
{
    int n;
    cin >> n;

    int count = count1Bits(n);
    cout << "Number of 1 bits in " << n << " is: " << count << endl;
    return 0;
}