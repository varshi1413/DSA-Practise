/*
Problem: Maximum Average Subarray I
Platform: LeetCode
Category: Sliding Window

Approach:
- Maintain a fixed-size sliding window of length k.
- Keep track of the current window sum.
- When the window exceeds size k, remove the leftmost element.
- Compute the average whenever the window size is exactly k and update the maximum average.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        double curr=0.0;
        double maxavg=INT_MIN;
        int sum=0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(right-left+1>k){
                sum-=nums[left];
                left++;
            }
            if(right-left+1==k){
                curr=(double)sum/k;
                maxavg=max(maxavg,curr);
            }
        }
        return maxavg;
    }
};