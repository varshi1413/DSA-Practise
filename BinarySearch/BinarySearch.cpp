/*
Problem: 704. Binary Search
Platform: LeetCode
Category: Binary Search

Approach:
- Initialize two pointers: left and right.
- Repeatedly calculate the middle index.
- If the middle element matches the target, return its index.
- If the target is greater, search the right half.
- If the target is smaller, search the left half.
- Continue until the search space becomes empty.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};