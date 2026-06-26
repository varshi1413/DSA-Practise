/*
Problem: Middle of the Linked List
Problem number:876
Platform: LeetCode
Technique: Slow & Fast Pointers

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};