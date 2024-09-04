 Reorder list

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the lists nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

SOLUTION:
step 1: point out the middle element
step 2: now reverse the 2nd half of linked list;
step 3: now attach alternatives to each other &continue  

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *prev =NULL, *cur=slow->next, *Next;
        while (cur) {
            Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        } 
        slow->next=NULL;

        // Merge the 2 halves
        ListNode *A = head, *B=prev;
        while (A && B) {
            ListNode* A_next=A->next;
            ListNode *B_next=B->next;

            A->next=B;
            B->next=A_next;

            A=A_next;
            B=B_next;
        }
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();