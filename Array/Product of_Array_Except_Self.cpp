/*
    Problem Link: https://leetcode.com/problems/product-of-array-except-self/description/
    Problem Name: Product of Array Except Self
    Difficulty  : Medium
    Time Complexity : O(N)
    Space Complexity: O()

*/

#include<bits/stdc++.h>
using namespace std;
// Solution using Divison operation
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, zeroCnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]) product *= nums[i];
            else zeroCnt++;
        }
        vector<int> ans;
        if(zeroCnt > 1){
            for(int i=0; i<nums.size(); i++){
                ans.push_back(0);
            }
        }
        else if(zeroCnt == 1){ 
            for(int i=0; i<nums.size(); i++){
                if(nums[i])ans.push_back(0);
                else{
                    ans.push_back(product);
                }
            }
        }
        else{
            for(int i=0; i<nums.size(); i++){
                ans.push_back(product/nums[i]);
            }
        }
        return ans;
    }
};