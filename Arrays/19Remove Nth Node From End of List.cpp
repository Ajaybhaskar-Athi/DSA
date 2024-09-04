Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
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
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode*temp=head;
    //     int len=0;
    //     while(temp!=NULL){
    //         len++;
    //         temp=temp->next;
    //     }
    //     if(n==len){
    //             ListNode*del=head;
    //             head=head->next;
    //             delete del;
    //             return head;
    //     }
    //     int pos=len-n;
    //     temp=head;
    //     while(pos>1){

    //     temp=temp->next;
    //     pos--;}
    //     ListNode*del=temp->next;
    //     temp->next=temp->next->next;
    //     delete del;
    //     return head;

    //     //TC=O(length)+O(length-n); in worst case it migth be 2(len) and sc=O(1);
    //     // so we need to optimise this
    // }



    ListNode* removeNthFromEnd(ListNode* head, int n) {

    // so here we have two pointers FAST and SLOW .
    //  lets take an example 1,2,3,4,5 and n=2 so we delete 4 for that i must be at 3 so at 3 i can do node->next=node->next->next

    // for that we follow below steps:

    // step 0: fast =head and slow=head;
    // step 1: starting from 1st node move FAST pointer N times
    // (here N=2 so we move fast will come at 3);
    // step 2: now after this move FAST and SLOW  simulataneously untill fast reaches to end of list

    // result: so we get slow pointer at 3rd position. so we can now do remaining

        ListNode*fast=head;
        ListNode*slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            //if it reaches last npode which happerns when question asks length th node from the end
            ListNode*del=head;
            head=head->next;
            delete head;
            return head;
        }
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode*del=slow->next;
        slow->next=slow->next->next;
        delete del;
        return head;
        }

};

SO HERE TIME COMPLEXITY=O(n)
since in both loops we have fast and it is goinng till last node which is length
    
// below also same code 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move the fast pointer n positions ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // Handle the case when the first element is to be removed
        if (fast == NULL) {
            return head->next;
        }
        
        // Move both pointers until the fast pointer reaches the end
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Remove the nth node from the end
        slow->next = slow->next->next;
        
        return head;
    }
};