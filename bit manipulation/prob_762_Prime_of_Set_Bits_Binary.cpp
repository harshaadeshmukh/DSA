/*
Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPrimeBits(int num)
{
    if(num <=1)
    {
        return false;
    }

    int size = sqrt(num);
    for(int i=2;i<=size;i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}
bool count1Bits(int temp)
{
    int numCount = 0;

    while(temp)
    {
        if(temp &1)
        {
            numCount++;
        }
        temp >>=1;
    }

    return isPrimeBits(numCount);
}
int countPrimeSetBits(int left , int right)
{
    int count = 0;
    for(int i = left ; i <= right ; i++)
    {
        if(count1Bits(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int left , right;

    cin>>left;
    cin>>right;

    int count = countPrimeSetBits(left , right);

    cout<<count<<endl;

}

