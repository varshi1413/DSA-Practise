/*
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode
Category: Sliding Window

Approach:
- Use a sliding window with two pointers.
- Maintain a set to store the unique characters in the current window.
- If a duplicate character is encountered, shrink the window from the left until the duplicate is removed.
- Update the maximum window length after processing each character.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int left=0,right=0;
        set<int> st;
        for(int right=0;right<s.size();right++){
            while(st.count(s[right])==1){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};