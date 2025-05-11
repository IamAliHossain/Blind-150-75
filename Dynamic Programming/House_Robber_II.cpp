/*
    Problem Link : https://leetcode.com/problems/house-robber-ii/description/
    Problem Name : 213. House Robber II
    Difficulty   : Medium
   
    Author : Ali Hossain
    Date : 11-05-2025

*/

#include<bits/stdc++.h>
using namespace std;

/*
        Time Complexity : O(n) exponential
        Space Complexity: O(n) + O(n) + call stack(n)
        The code is in memoiation technique
*/

class Solution {
public:
    // Making array linear by skiping once 1st index and once last index to avoid neigboring state
    int money(int ind, int lastInd, vector<int>& nums, vector<int>& dp){
        if(ind > lastInd) return 0;
        if(ind == lastInd) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + money(ind+2, lastInd, nums, dp);
        int notPick = 0 + money(ind+1, lastInd, nums, dp);
        dp[ind] = max(pick, notPick);
        return dp[ind];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        // To make it easier made it linear by skipping one index
        int skip_1st_index = money(1, n-1, nums, dp1);
        int skip_last_index = money(0, n-2, nums, dp2);

        return max(skip_1st_index , skip_last_index);
        
    }
};