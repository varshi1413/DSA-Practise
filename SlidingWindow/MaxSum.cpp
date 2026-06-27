/*
Problem: Maximum Sum of Distinct Subarrays With Length K
Problem nummber:2461
Platform: LeetCode
Category: Sliding Window

Approach:
- Maintain a sliding window using two pointers.
- Use a set to ensure all elements in the current window are distinct.
- If a duplicate is found or the window size reaches k, shrink the window from the left.
- Track the current window sum and update the maximum sum whenever the window contains exactly k distinct elements.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/
#include<algorithm>
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {   
        int left=0;
        long maxsum=0;
        long current=0;
        set<int> s;
        for(int right=0;right<nums.size();right++){
            while(s.count(nums[right])==1||s.size()==k){
                s.erase(nums[left]);
                current-=nums[left];
                left++;
            }
            s.insert(nums[right]);
            current+=nums[right];
            if(s.size()==k){
                maxsum=max(maxsum,current);
            }
        }
        return maxsum;
    }
};