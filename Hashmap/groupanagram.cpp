/*
    Problem No.   : 49
    Problem Name  : Group Anagrams
    Platform      : LeetCode
    Difficulty    : Medium
    Category      : Hash Map, String, Sorting

    Approach:
    - Sort each string to create a canonical key.
    - Group original strings using an unordered_map<sorted_string, vector<string>>.
    - Collect all grouped values into the result.

    Time Complexity : O(n * k log k)
    Space Complexity: O(n * k)

    Where:
    n = Number of strings
    k = Maximum length of a string
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(auto s:strs){
            string st=s;
            sort(st.begin(),st.end());
            mp[st].push_back(s);
        }
        for(auto &entry:mp){
            res.push_back(entry.second);
        }
        return res;
    }
};