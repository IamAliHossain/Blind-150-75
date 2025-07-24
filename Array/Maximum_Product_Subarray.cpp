/*
    Problem Link: https://leetcode.com/problems/maximum-product-ubarray/description/
    Problem Name: Maximum Product Subarray
    Difficulty  : Medium
    Time Complexity : 
    Space Complexity: 

    Given an integer array nums, return an array answer such that answer[i] is equal to 
    the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array 
does not count as extra space for space complexity analysis.)


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

/*
    This solution is mine after 45 minutes of brainstorming : 

    যেই index এ আছি সেই index এর আগের prefix product & তার পরের index এর suffix product 
    multiply করে ঐ index এর product পাবো except that index, এজন্য we need a prefix product array 
    যেটা index er left part er product bear করবে & একটা suffix product array লাগবে 
    যেটা কোন index এর right part এর suffix product bear করবে ।

    কোন index এর product except that index = prefProduct[index-1] * suffixProduct[inex+1]
 
    TC : O(N)
    SC : O(N) + O(N) : O(N)

    Follow Up task for Space Complexity is O(!) where I used O(N) that's why I need to 
    optimize that which added in the next solution 3
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefProd(n), suffProd(n);
        prefProd[0] = nums[0];
        suffProd[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            prefProd[i] = prefProd[i-1] * nums[i];
        }
        for(int i=n-2; i>=0; i--){
            suffProd[i] = suffProd[i+1] * nums[i];
        }
        for(int i=0; i<n; i++){
            if(i == 0){
                nums[i] = suffProd[i+1];
            }
            else if(i == n-1){
                nums[i] = prefProd[i-1];
            }
            else{
                nums[i] = prefProd[i-1] * suffProd[i+1];
            }
        }
        return nums;
    }
};

/*
    Time Complexity : O(n) and Space Complexity O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    // vector<int> nums = {1,0,-1,2,3,-5,-2};
    // vector<int> nums = {-3,0,1,-2};
    // vector<int> nums = {-2,0,-1};
    int n = nums.size();
    int pref = 1, suff = 1, maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(pref == 0){
            pref = 1;
        }
        if(suff == 0){
            suff = 1;
        }
        pref = pref * nums[i];
        suff = suff * nums[n-i-1];
        maxi = max(maxi, max(pref, suff));
    }
    cout << maxi << endl;
    }
};