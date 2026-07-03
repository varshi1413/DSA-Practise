/*
Problem: Continuous Subarray Sum
Platform: LeetCode
Category: Prefix Sum, Hash Map

Approach:
- Maintain a running prefix sum while traversing the array.
- Compute the remainder of the prefix sum with k at each index.
- Use an unordered_map to store the first occurrence index of each remainder.
- If the same remainder appears again and the distance between indices is at least 2,
  then the subarray sum is divisible by k.
- Initialize the map with {0, -1} to handle subarrays starting from index 0.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int rem;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem = sum % k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>1){
                    return true;
                }
            }
            else{
                mp[rem]=i;
            }
            
        }
        return false;
    }
};