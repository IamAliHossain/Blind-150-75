/*
    Problem Link : https://leetcode.com/problems/unique-paths/description/
    Problem Name : 62. Unique Paths
    Difficulty   : Medium
    
    Author : Ali Hossain
    Date : 12-05-2025

    Problem Statement:

    There is a robot on an m x n grid. The robot is initially located at the top-left corner 
    (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
    The robot can only move either down or right at any point in time.

    Given the two integers m and n, return the number of possible unique paths that the 
    robot can take to reach the bottom-right corner.

    The test cases are generated so that the answer will be less than or equal to 2 * 109.

    

    Example 1:


    Input: m = 3, n = 7
    Output: 28
    Example 2:

    Input: m = 3, n = 2
    Output: 3
    Explanation: From the top-left corner, there are a total of 3 ways to reach the 
    bottom-right corner:
    1. Right -> Down -> Down
    2. Down -> Down -> Right
    3. Down -> Right -> Down
    

    Constraints:

    1 <= m, n <= 100

*/

#include<bits/stdc++.h>
using namespace std;

/* Memoization Technique :

    dp array এর dimension নির্ভর করে হচ্ছে function কয়টা arguments এর উপর নির্ভর করছে তার উপর
    এখানে i & j এই 2 টার উপর নির্ভর করে তাই 2D DP হবে M * N অতএব dp[M][N]

    Where TC : O(M * N) traversing through the array & 
    SC : O(M+N) auxilary stack space + O(M * N) for using dp array so overrall SC : O(M * N)

    Time Complexity : O(M * N) = O(M*N)
    Space Complexity : O(M*N)

*/

// solution 1
class Solution {
public:
    int numOfUniquePaths(int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int rightMove = numOfUniquePaths(i, j+1, n, m, dp);
        int downMove = numOfUniquePaths(i+1, j, n, m, dp);
        return dp[i][j] = rightMove + downMove ;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return numOfUniquePaths(0, 0, m, n, dp);
    }
};

// both solution approach are same just variable naming is different don't be bother
class Solution {
public:
    //This is recursive solution to optimize TC used DP(memoiation)
    int paths(int i, int j, int n, int m, vector<vector<int>> &dp){
        if(i >= n || j >= m) return 0;
        if(i == n-1 && j == m-1) return 1;
        if(dp[i][j] != -1) return dp[i][j] ;
        int ans = 0;
        ans += paths(i+1, j, n, m, dp) + paths(i, j+1, n, m, dp);
        dp[i][j] = ans;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return paths(0, 0, m, n, dp);
    }
};