//231. Power of Two
//326. Power of Three
//342. Power of Four

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int temp)
{
    if(temp <=0)
    {
        return false; // Negative numbers and zero are not powers of two
    }

    return (temp &(temp - 1)) == 0; // A number is a power of two if it has only one bit set
}


bool isPowerOfThree(int temp)
{
    if(temp <= 0)
    {
        return false; // Negative numbers and zero are not powers of three
    }

    while(temp%3==0)
    {
        temp = temp/3;
    }

    return temp == 1; // A number is a power of three if it can be reduced to 1 by dividing by 3
}


bool isPowerOfFour(int temp)
{
    if(temp <=0)
    {
        return false;
    }

    while(temp %4==0)
    {
        temp = temp/4;
    }
    return temp == 1; // A number is a power of four if it can be reduced to 1 by dividing by 4
}
int main()
{
    int n2;
    cin >> n2;

    // Check if n2 is a power of 2
    bool flag2 = isPowerOfTwo(n2);

    if(flag2)
    {
        cout << n2 << " is a power of 2" << endl;
    }
    else
    {
        cout << n2 << " is not a power of 2" << endl;
    }
    cout << endl;


    int n3 ;
    cin >> n3;

    bool flag3 = isPowerOfThree(n3);
    if(flag3)
    {
        cout << n3 << " is a power of 3" << endl;
    }
    else
    {
        cout << n3 << " is not a power of 3" << endl;
    }

    cout << endl;

    int n4;
    cin >> n4;

    bool flag4 = isPowerOfFour(n4);
    if(flag4)
    {
        cout << n4 << " is a power of 4" << endl;
    }
    else
    {
        cout << n4 << " is not a power of 4" << endl;
    }
    return 0;
}