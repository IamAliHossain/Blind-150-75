/*
    Problem Link: https://leetcode.com/problems/maximum-subarray/description/
    Problem Name: Maximum Subarray
    Difficulty  : Medium
    Time Complexity : O(N)
    Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> pref, suff;
        int n = nums.size();
        int sum = nums[0], mxSum = nums[0], l = 0, r = 0 ;
        for(int i=1; i<n; i++){
            sum = max(sum + nums[i], nums[i]);
            mxSum = max(mxSum, sum);
        }
        return mxSum;
    }
};