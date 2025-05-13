/*
    Problem Link: https://leetcode.com/problems/product-of-array-except-self/description/
    Problem Name: Product of Array Except Self
    Difficulty  : Medium
    Time Complexity : O(N)
    Space Complexity: O()

*/

#include<bits/stdc++.h>
using namespace std;
// Solution using Divison operation go below for best solution
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

/*
    The beutiful technique but too simple to think The logic behind the scene is 
    ith index contain the multiplicaiton of [0, i-1] indices and 
    [i+1, n-1] indices that means for any a[i] = a0 * a1 * a[i-1] * a[i+1] * a[i+2] ...* a[n-1] 

*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n); 
       
        left[0] = 1, right[n-1] = 1;
        
        for(int i=1; i<n; i++){
            left[i] = left[i-1] * nums[i-1];
        }

        for(int i=n-2; i>=0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};