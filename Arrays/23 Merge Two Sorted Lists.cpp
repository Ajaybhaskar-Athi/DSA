ou are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

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
    ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
        if(!List1 || !List2){
            return List1==NULL?List2:List1;
        }
        ListNode*ft=new ListNode(-1); //fake tail
        ListNode*fh=ft;//fake head
        ListNode*t1=List1;
        ListNode*t2=List2;

        while(t1&&t2){
            if(t1->val<=t2->val){
                ft->next=t1;
                t1=t1->next;
            }
            else{
                ft->next=t2;
                t2=t2->next;
            }
            ft=ft->next;
        }
        if(t1||t2){
            ft->next=(t1==NULL?t2:t1);
        }
        return fh->next;
    }
};