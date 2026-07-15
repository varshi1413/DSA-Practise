/*
    Problem No.   : 290
    Problem Name  : Word Pattern
    Platform      : LeetCode
    Difficulty    : Easy
    Category      : Hash Map, String

    Approach:
    1. Split the input string into individual words using stringstream.
    2. If the number of words and the pattern length differ, return false.
    3. Maintain two hash maps to enforce a one-to-one (bijective) mapping:
         - char   -> string
         - string -> char
    4. Traverse the pattern and words simultaneously:
         - If the pattern character is already mapped, verify it maps to the current word.
         - Otherwise, ensure the current word is not already mapped to another character.
         - If both are new, insert the mapping into both hash maps.
    5. If all mappings remain consistent, return true.

    Time Complexity : O(n)
    Space Complexity: O(n)

    Where:
    n = Length of the input string (or equivalently, the number of words after splitting).
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word){
            words.push_back(word);
        }
        if(pattern.size()!=words.size()){
            return false;
        }
        unordered_map<char,string> mp;        
        unordered_map<string,char> mp1;   
        for(int i=0;i<words.size();i++){
            auto it=mp.find(pattern[i]);
            auto it1=mp1.find(words[i]);
            if(it!=mp.end()){
                if(it->second!=words[i]){
                    return false;
                }
            }
            else{
                if(it1!=mp1.end()){
                    return false;
                }
                mp.emplace(pattern[i],words[i]);
                mp1.emplace(words[i],pattern[i]);
            }
        }
        return true;
    }                
};