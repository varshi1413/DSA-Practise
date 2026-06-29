/*
Problem: Merge Two Sorted Lists
Platform: LeetCode
Category: Linked List

Approach:
- Create a dummy node to simplify the merging process.
- Use a tail pointer to build the merged linked list.
- Compare the current nodes of both lists.
- Append the smaller node to the merged list and move the corresponding pointer.
- After one list is exhausted, attach the remaining nodes of the other list.

Time Complexity: O(n + m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        ListNode* list3=new ListNode(0);
        ListNode* head=list3;
        ListNode* h1=list1;
        ListNode* h2=list2;
        while(h1!=NULL&&h2!=NULL){
            if(h1->val<=h2->val){
                list3->next=h1;
                h1=h1->next;
                list3=list3->next;
            }
            else{
                list3->next=h2;
                h2=h2->next;
                list3=list3->next;
            }
        }
        if(h1==NULL){
            list3->next=h2;
        }
        else{
            list3->next=h1;
        }
        return head->next;
    }
};