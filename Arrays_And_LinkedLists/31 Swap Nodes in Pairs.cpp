Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the lists nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 






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
   
    ListNode* swapPairs(ListNode* head) {
    // If the list is empty or has only one node, no need to swap
    if (!head || !head->next)
        return head;

    // Dummy node to handle edge cases
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* current = head;

    while (current && current->next) {
        ListNode* nextPair = current->next->next;

        // Swap the current pair
        prev->next = current->next;
        current->next->next = current;
        current->next = nextPair;

        // Move prev and current pointers forward
        prev = current;
        current = nextPair;
    }

    ListNode* newHead = dummy->next;
    delete dummy; // Free the dummy node

    return newHead;
}

};