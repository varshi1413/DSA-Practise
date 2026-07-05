/*
Problem: 435. Non-overlapping Intervals
Platform: LeetCode
Category: Greedy, Sorting, Intervals

Approach:
- Sort all intervals based on their ending time.
- Keep the first interval and store its ending time.
- Traverse the remaining intervals:
  - If the current interval overlaps with the previously kept interval,
    remove the current interval by increasing the removal count.
  - Otherwise, keep the current interval and update the previous ending time.
- Return the minimum number of intervals removed.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int removed=0;
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(),[](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int prevEnd=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(prevEnd>intervals[i][0]){
                removed++;   
            }
            else{
                prevEnd=intervals[i][1];
            }
        }
        return removed;
        
    }
};