/*
Problem: Merge Intervals
Platform: LeetCode
Category: Sorting, Intervals

Approach:
- Sort the intervals based on their starting time.
- Initialize the result with the first interval.
- Traverse the remaining intervals one by one.
- If the current interval overlaps with the last merged interval,
  update the ending point of the last merged interval.
- Otherwise, add the current interval to the result.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(auto interval:intervals){
            if(res.back()[1]>=interval[0]){
                int start=min(res.back()[0],interval[0]);
                int end=max(res.back()[1],interval[1]);
                res.back()[0]=start;
                res.back()[1]=end;
            }
            else{
                res.push_back(interval);
            }
        }
        return res;
    }
};