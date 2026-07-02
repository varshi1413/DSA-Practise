/*
Problem: Subarray Sum Equals K
Platform: LeetCode
Category: Prefix Sum, Hash Map

Approach:
- Maintain a running prefix sum while traversing the array.
- Use an unordered_map to store the frequency of each prefix sum encountered.
- For each element, check if (currentPrefixSum - k) exists in the map.
- If it exists, add its frequency to the answer since each occurrence represents a valid subarray.
- Store the current prefix sum by incrementing its frequency in the map.
- Initialize the map with {0,1} to handle subarrays starting from index 0.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(mp.find(sum - k) != mp.end())
            {
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};