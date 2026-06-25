/*
Problem: Linked List Cycle
Problem number:141
Platform: LeetCode
Technique: Floyd's Cycle Detection (Slow & Fast Pointers)

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};