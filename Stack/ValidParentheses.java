/*
    Problem No.   : 20
    Problem Name  : Valid Parentheses
    Platform      : LeetCode
    Category      : Stack
    Approach      : Push expected closing brackets onto the stack and validate each closing bracket while traversing the string.
    Time Complexity : O(n)
    Space Complexity: O(n)
*/
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st=new Stack<>();
        for(int i=0;i<s.length();i++){
            char s1=s.charAt(i);
            if(s1=='('){
                st.push(')');
            }
            else if(s1=='{'){
                st.push('}');
            }
            else if(s1=='['){
                st.push(']');
            }
            else if(st.isEmpty() || st.pop()!=s1){
                return false;
            }
        }
        if(!st.isEmpty()){
            return false;
        }
        return true;
    }
}