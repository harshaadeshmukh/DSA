/*
We are given an array asteroids of integers representing asteroids in a row. 
The indices of the asteriod in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:
Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:
Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
vector<int> solve(vector<int> &asteroids)
{
     stack<int>st;

        for(int i =0;i<asteroids.size();i++)
        {
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                int sum = asteroids[i] + st.top();

                if(sum < 0)
                {
                    st.pop();
                }
                else if(sum > 0)
                {
                    asteroids[i] = 0;
                }
                else{
                    asteroids[i] = 0;
                    st.pop();
                }
            }

            if(asteroids[i]!=0)
            {
                st.push(asteroids[i]);
            }
        }

        int size = st.size();

        vector<int> ans(size);

        while(size!=0)
        {
            ans[size-1] = st.top();
            st.pop();
            size--;
        }
        return ans;
}

int main()
{
    int n ;
    cin >> n;

    vector<int> asteroids(n);
    for(int i =0;i<n;i++)
    {
        cin >> asteroids[i];
    }

    vector<int> result = solve(asteroids);
    for(auto x: result)
        cout<<x<<" ";

    return 0;
}