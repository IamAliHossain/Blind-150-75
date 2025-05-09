/*
    Problem Link : https://leetcode.com/problems/coin-change/description/
    Problem Name : 322. Coin Change
    Difficulty   : Medium
    Time Complexity : O()
    Space Complexity: O()

    Author : Ali Hossain
    Date : 10-05-2025

    You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.

    

    Example 1:

    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
    Example 2:

    Input: coins = [2], amount = 3
    Output: -1
    Example 3:

    Input: coins = [1], amount = 0
    Output: 0
    

    Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int l(vector<int> &coins, int amount){
        
        int dp[amount+1];
        for(int i=1; i<=amount; i++){
            dp[i] = amount;
        }
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(auto coin : coins){
                if(i-coin < 0) continue;
                dp[i] = min(dp[i-1], 1+dp[i-coin]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
