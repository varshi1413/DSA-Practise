/*
Problem: Palindrome Linked List
Platform: LeetCode
Category: Linked List

Approach:
- Find the middle of the linked list using slow and fast pointers.
- If the list has an odd number of nodes, skip the middle node.
- Reverse the second half of the list.
- Compare the first half with the reversed second half.
- If all corresponding nodes match, the list is a palindrome.

Time Complexity: O(n)
Space Complexity: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode* slow=head;     
        ListNode* fast=head;
        while(fast != NULL && fast->next != NULL)     {
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast != NULL) {
            // Odd number of nodes
            slow = slow->next;   // Skip the middle node
        }
        ListNode* curr=slow;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        slow=head;
        while (prev != NULL) {
            if (prev->val != slow->val)
                return false;

            prev = prev->next;
            slow = slow->next;
        }

        return true;
    }
};