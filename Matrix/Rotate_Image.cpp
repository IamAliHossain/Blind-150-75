/*
    Problem : https://leetcode.com/problems/rotate-image/
    Problem name : Rotate Image
    Difficulty : Medium

    Time Complexity : O(N * N)
    Space Complexity: O(N * N) since ans vector is used

*/

#include<bits/stdc++.h>
using namespace std;

// Solution for 90 degree rotate a Matrix

class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int> (n, 0));
        int k = n-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                ans[j][k] = matrix[i][j]; // ith row is stored at (n-i)th col, means 1st row jabe last col e and so on
            }
            k--;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};