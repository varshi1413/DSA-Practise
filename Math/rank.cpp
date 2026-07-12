/*
 * LeetCode 1331 - Rank Transform of an Array
 * Platform  : LeetCode
 * Category  : Array, Sorting, Hash Map
 *
 * Approach:
 * 1. Insert all elements into a set to obtain unique values in sorted order.
 * 2. Traverse the set and assign ranks (starting from 1) using an unordered_map.
 * 3. Replace each element in the original array with its corresponding rank.
 *
 * Time Complexity : O(n log n)
 * Space Complexity: O(n)
 */
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(),arr.end());
        int r=1;
        unordered_map<int,int> rank;
        vector<int> result(arr.size());
        for(int x:s){
            rank[x]=r++;
        }
        for(int i=0;i<arr.size();i++){
            result[i]=rank[arr[i]];
        }
        return result;  
    }
};