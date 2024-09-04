Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 



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
    ListNode* removeElements(ListNode* head, int val) {
//this is like method how we merging the two sorted linked lists by creating fake head and fake tail
        //cr26 Reorder List.cppeating a fake tail to acces the 1st element of list
       ListNode* removeElements(ListNode* head, int val) {
    ListNode *fakeHead = new ListNode(0);
    fakeHead->next = head;
    ListNode *fakeTail = fakeHead;

    while (fakeTail->next != NULL) {
        if (fakeTail->next->val == val) {
            fakeTail->next = fakeTail->next->next;
        } else {
            fakeTail = fakeTail->next;
        }
    }

    return fakeHead->next;
}

};