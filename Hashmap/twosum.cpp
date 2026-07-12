/*
-------------------------------------------------------
LeetCode 1. Two Sum
Platform : LeetCode
Category : Array, Hash Table

Approach:
- Traverse the array once while maintaining a hash map
  that stores each number and its index.
- For every element, compute the required complement
  (target - current element).
- Check if the complement already exists in the hash map.
- If found, return the stored index and the current index.
- Otherwise, insert the current element and its index
  into the hash map and continue.

Time Complexity : O(n) average
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> res;
        for(int i=0;i<nums.size();i++){
            auto it=res.find(target-nums[i]);
            if(it!=res.end()){
                return {it->second,i};
            }
            else{
                res.insert({nums[i],i});
            }
        }
        return {};
    }
};