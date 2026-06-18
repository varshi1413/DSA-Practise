/*
Problem: Valid Palndrome
Problem Number-125
Platform: LeetCode

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        for(auto &n: s){
            n=tolower(n);
            if(isalnum(n)){
                res+=n;
            }
        }
        if(res.empty()) return true;
        int i=0,j=res.size()-1;
        while(i<j){
            if(res[i]==res[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};