/*
    Problem Link : https://leetcode.com/problems/combination-sum-iv/
    Problem Name : 377. Combination Sum IV
    Difficulty   : Medium
    TC : O(n* target)
    SC : O(N)
    Author : Ali Hossain
    Date : 10-05-2025


 */

#include<bits/stdc++.h>
using namespace std;

/*
    This recursive solution leads TLE
    N = nums.size()
    T = target
    TC : O(N * T)
    SC : O(N * T)
    Now to solve TLE problem use memoization technique

    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে index & target এই 2 টার উপর নির্ভর করে তাই 2D DP হবে। index can be N ও target তাই 
    N * Target। 
    অতএব dp[N][Target+1]

*/

/*-------------------------------Recursive Solution Ends---------------------------------------------*/



/*-------------------------------Memoizstion Solution Starts---------------------------------------------
    This recursive solution leads TLE
    N = nums.size()
    T = target
    TC : O(N * T)
    SC : O(N * T)
    Now to solve TLE problem use memoization technique

    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে index & target এই 2 টার উপর নির্ভর করে তাই 2D DP হবে। index can be N ও target তাই 
    N * Target। 
    অতএব dp[N][Target+1]

*/
class Solution {
public:
    long long ways(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[index][target] != -1) return dp[index][target];
        int ans = 0;
        // This for loop is used instead of take/notTake technique because this take
        //different sequences are counted as different combinations 4 = 1+3 and 4 = 3+1 are two different combinations
        for(int i=0; i<nums.size(); i++){
            ans += ways(i, target-nums[i], nums, dp);
        }
        
        return dp[index][target] = ans;

    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return ways(n-1, target, nums, dp);
    }
};

// memoization solution2

class Solution {
public:
    long long ways(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
        
        if(target < 0) return 0;
        if(target == 0) return 1;
        if(dp[index][target] != -1) return dp[index][target];
        int ans = 0;
        // This for loop is used instead of take/notTake technique because this take
        //different sequences are counted as different combinations 4 = 1+3 and 4 = 3+1 are two different combinations
        for(int i=0; i<nums.size(); i++){
            ans += ways(i, target-nums[i], nums, dp);
        }
        
        return dp[index][target] = ans;

    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return ways(n-1, target, nums, dp);
    }
};
/*-------------------------------Memoizstion Solution Ends---------------------------------------------*/




/*-------------------------------Tabulation Solution Starts---------------------------------------------*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(target+1, 0); 
        dp[0]=1;
        for(int i=1; i<=target; i++){
            for (int x: nums){
                if (i>=x)
                    dp[i]+=dp[i-x];
            }
        }
        return dp[target];
    }
};