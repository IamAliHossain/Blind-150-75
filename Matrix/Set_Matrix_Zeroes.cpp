/*
    Problem Link : https://leetcode.com/problems/set-matrix-zeroes/
    Difficulty   : Medium
    Problem Name : Set Matrix Zeroes
*/

/*  
    Better Solution
    Time Complexity : O(N*M)
    Space Complexity: O(N + M)

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> rowSe, colSe;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    rowSe.insert(i);
                    colSe.insert(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(rowSe.find(i) != rowSe.end()){
                for(int col=0; col<m; col++){
                    matrix[i][col] = 0;
                }
            }
        }
        for(int j=0; j<m; j++){ 
            if(colSe.find(j) != colSe.end()){
                for(int row=0; row<n; row++){
                    matrix[row][j] = 0;
                }
            }
        }
        
    }
};

/*  
    Optimal Solution
    Time Complexity : O(N*M)
    Space Complexity: O(1)
*/