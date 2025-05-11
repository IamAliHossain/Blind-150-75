/*
    Problem Link : https://leetcode.com/problems/house-robber/description/
    Problem Name : House Robber
    Difficulty   : Medium
   
    Author : Ali Hossain
    Date : 11-05-2025

*/



#include<bits/stdc++.h>
using namespace std;
/*

    Time Complexity : O(n ) exponential
    Space Complexity: O(n) + call stack(n)

    The code is in memoiation technique
*/

class Solution {
public:
    int money(int ind, vector<int> &nums, vector<int> &dp){
        if(ind > nums.size() -1) return 0;
        if(ind == nums.size() - 1) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        int pick =nums[ind] + money(ind+2, nums, dp);
        int notPick = 0 + money(ind+1, nums, dp);
        dp[ind] = max(pick, notPick);
        return dp[ind];

    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return money(0, nums, dp);
    }
};