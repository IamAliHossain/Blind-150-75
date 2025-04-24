/*
    Problem Link: https://leetcode.com/problems/maximum-product-ubarray/description/
    Problem Name: Maximum Product Subarray
    Difficulty  : Medium
    Time Complexity : O(N)
    Space Complexity: O(N)

*/

#include<bits/stdc++.h>
using namespace std;
//Updated Version of Kadanas Algorithm
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mxResProd = nums[0];
        vector<int> dpMx(n), dpMn(n);
        dpMx[0] = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] == 0){
                dpMx[i] = 1;
                dpMn[i] = 1;
                mxResProd = max({mxResProd, dpMx[i-1], dpMn[i-1]});
                continue;
            }
            dpMx[i] = max({dpMx[i-1] * nums[i], dpMn[i-1] * nums[i], nums[i]});
            dpMn[i] = min({dpMx[i-1] * nums[i], dpMn[i-1] * nums[i], nums[i]});
            mxResProd = max({mxResProd, dpMx[i], dpMn[i]});
        }
        return mxResProd;
    }
};