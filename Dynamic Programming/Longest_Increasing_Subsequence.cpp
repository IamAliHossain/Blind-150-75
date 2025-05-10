/*
    Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/description/
    Problem Name : 300. Longest Increasing Subsequence70. Climbing Stairs
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 09-05-2025


    */

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // This code is done with just recursive hence TC = O(2^n) and brings TLE
    // To optimize the code we apply dp here, so see the next part
    //      Time Complexity : O(2^n)
    //      Space Complexity : O(1) 
    int LIS(int ind, int prev_ind, vector<int> &arr, int n){
        if(ind == n) return 0;
        int lenByNotTaking, lenByTaking , maxLen;
        lenByNotTaking = 0 + LIS(ind+1, prev_ind, arr, n);
        if(prev_ind == -1 || arr[ind] > arr[prev_ind]){ 
            lenByTaking = 1 + LIS(ind+1, ind, arr, n);
        }
        maxLen = max(lenByNotTaking, lenByTaking);

        return maxLen;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return LIS(0, -1, nums, n);
    }
    

    /*====================================================================================
    ==============  Optimized code using dp solution(memoiation technique)  ==============
    ======================================================================================*/

    //      Time Complexity : O(n * n) = O(n^2)
    //      Space Complexity : O(N) 

    int LIS(int ind, int prev_ind, vector<int> &arr, vector<vector<int>> &dp, int n){
        if(ind == n) return 0;
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        int lenByNotTaking, lenByTaking , maxLen;
        lenByNotTaking = 0 + LIS(ind+1, prev_ind, arr, n);
        if(prev_ind == -1 || arr[ind] > arr[prev_ind]){ 
            lenByTaking = 1 + LIS(ind+1, ind, arr, n);
        }
        maxLen = max(lenByNotTaking, lenByTaking);

        return dp[ind][prev_ind+1] = maxLen; /*dp[ind][prev_ind] ---> means LIS length from prev_ind to ind */
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        int n = nums.size();
        return LIS(0, -1, nums, dp, n);
    }
};