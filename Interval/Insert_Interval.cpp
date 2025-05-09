/*
    Problem Link : https://leetcode.com/problems/insert-interval/description/
    Problem Name : 57. Insert Interval
    Difficulty   : Medium
    Time Complexity : O(N*M)
    Space Complexity : O(N*M)
    ================================================================================================


    You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

    Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

    Return intervals after the insertion.

    Note that you don't need to modify intervals in-place. You can make a new array and return it.

    

    Example 1:

    Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    Output: [[1,5],[6,9]]
    Example 2:

    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
    

    Constraints:

    0 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 105
    intervals is sorted by starti in ascending order.
    newInterval.length == 2
    0 <= start <= end <= 105

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result, temp;
        for(int i=0; i<intervals.size(); i++){
            temp.push_back(intervals[i]);
        }
        temp.push_back(newInterval);
        sort(temp.begin(), temp.end());
        result.push_back(temp[0]);
        for(int i=1; i<temp.size(); i++){
            int start = temp[i][0];
            int end = temp[i][1];
            if(result.back()[1] < temp[i][0]){
                result.push_back(temp[i]);
            }
            else{
                result.back()[1] = max(result.back()[1], temp[i][1]);
            }
        }
        return result;
    }
};