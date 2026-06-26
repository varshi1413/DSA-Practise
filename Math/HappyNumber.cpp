/*
Problem: Happy Number
Platform: LeetCode
Category: Math

Approach:
- Treat each number as a node.
- Next node = sum of squares of its digits.
- Use Floyd's Cycle Detection.
- If the fast pointer reaches 1, the number is happy.
- If slow and fast meet before reaching 1, a cycle exists, so the number is not happy.

Time Complexity: O(log n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool isHappy(int n) {
        int slow=square(n);
        int fast=square(square(n));
        while(slow!=fast&&fast!=1){
            slow=square(slow);
            fast=square(square(fast));    
        }
        return slow == 1||fast==1; 
    }
    int square(int n){
        int ans=0,num;
        while(n>0){
            num=n%10;
            ans+=(num*num);
            n/=10;
        }
        return ans;
    }
};
