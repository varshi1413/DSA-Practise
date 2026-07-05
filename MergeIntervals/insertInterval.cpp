/*
Problem: 57. Insert Interval
Platform: LeetCode
Category: Intervals

Approach:
- Traverse each interval from left to right.
- If the current interval ends before the new interval starts, add it to the result.
- If the current interval overlaps with the new interval, merge them by updating the start and end of the new interval.
- If the current interval starts after the new interval ends, insert the merged interval, append the remaining intervals, and return.
- If the new interval is not inserted during traversal, add it at the end.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);   
            }
            else if(newInterval[1]>=intervals[i][0] && intervals[i][1]>=newInterval[0]){
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);   
            }
            else{
                res.push_back(newInterval);
                for(int j=i;j<intervals.size();j++){
                    res.push_back(intervals[j]);
                }
                return res;
            }
        }
        res.push_back(newInterval);
        return res;
    }
};