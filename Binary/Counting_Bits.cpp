/*
    Problem Link: https://leetcode.com/problems/counting-bits/description/
    Problem Name: Counting Bits
    Difficulty  : Easy
    Time Complexity : O(n * long N)
    Space Complexity: O(N)


=======================================================================================================

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
 

Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            int setBit = 0;
            int j = i ;
            while(j != 0){
                if(j & 1){
                    setBit++;
                }
                j = (j >> 1);
            }
            ans.push_back(setBit);
        }
        return ans;
    }
};

/*
    Better Approach : DP solution
    Time Complexity : O(N)
    Space Complexity: O(N)
*/

class Solution{
    public:
    vector<int>countBits(int n){
        vector<int> dp(n, 0);
        for(int i=1; i<=n; i++){
            dp[i] = (i & (i - 1)) + 1;
        }
        return dp;
    }
};