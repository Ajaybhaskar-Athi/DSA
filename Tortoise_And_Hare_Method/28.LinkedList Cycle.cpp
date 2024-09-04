/*

Detecting a cycle in a linked list using the //**TWO POINTER APPROACH//** is a well-known technique called Floyd's Cycle Detection Algorithm,
 also known as the Tortoise and Hare algorithm. The idea is to use two pointers that move at different speeds through the list.
  If there is a cycle, the fast pointer (hare) will eventually meet the slow pointer (tortoise). 
  If there is no cycle, the fast pointer will reach the end of the list.
*/








A linked list cycle, also known as a cycle or loop,
 occurs when a linked list contains a sequence of nodes
  where one node points back to a previously visited node, 
  creating a closed loop.
    a list has a loop it means it has never end => nevr has next pointer =NULL;
    may be last node points to any other node;
// points 
1) Linear linked list does not have a cycle since there last node always points to NULL

So WE r Using TORTOISE and HARY method where we use this before in find midpoint of linked list and finding duplicates in an array
// slow and fast intially pointed to head .slow move by one pointer and fast move ny two pointers
//we stop if they intersect means they have a loop .
2) if it was odd length linear list then by moving slow and fast ptrs we get fast at the end of list 
so we stop if fast->next!=NULL;
3) if there was even length linear list then slow stops before last node but fast go to after last node which become fast =null;
so we do iteration uto fast!=NULL . so fast!=NULL && fast->next!=null


WE DIDNT KNOW IT HAS A CYLCE OR NOT BY SEEING  like below they made a cycle



 // Example usage





    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node1; // Creating a cycle


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //TORTOISE AND HARE METHOD
        if(!head)return false;
        bool f=false;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
        //for finding the starting node of cylce we intialise one of slow ,fast lets say i take fast=nums[0] and slow is still at intersection 
        // now by moving both slow,fast by one pointers we get the desired starting node of cylce when both intersect
        // fast=head;
        // while(slow!=fast){
        //     slow=slow->next;
        //     fast=fast->next;
        // }
        // cout<<slow->val;
    }
};