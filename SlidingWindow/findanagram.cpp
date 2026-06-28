/*
Problem: Find All Anagrams in a String
Platform: LeetCode
Category: Sliding Window

Approach:
- Maintain a fixed-size sliding window equal to the length of the pattern.
- Use two frequency arrays:
  - One for the current window.
  - One for the pattern.
- Compare the frequency arrays whenever the window size equals the pattern length.
- If they match, the current window is an anagram.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<algorithm>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left=0;
        vector<int> result;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(char ch:p){
            freq2[ch-'a']++;
        }
        for(int right=0;right<s.size();right++)    {
            freq1[s[right]-'a']++;
            if(right-left+1==p.size()&&freq1==freq2){
                result.push_back(left);
            }
            if(right-left+1>p.size()){
                freq1[s[left]-'a']--;
                left++;
                if(right-left+1==p.size()&&freq1==freq2){
                    result.push_back(left);
                }
            }
        }
        return result;      
    }
};