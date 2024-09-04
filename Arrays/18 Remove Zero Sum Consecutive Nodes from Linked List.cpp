/*Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 
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
    // ListNode* removeZeroSumSublists(ListNode* head) {
    //     ListNode*curr=head;
    //     ListNode*prev=NULL; 
    //     // ListNode*
    //     while(curr->next!=NULL){
    //         if(curr->val+curr->next->val==0){
    //             prev->next=curr->next->next;
    //             curr=prev;
    //         }   
    //         else{
    //             prev=curr;
    //             curr=curr->next;
    //         }
    //     }
    //     return head;
    // with these method our 3rd test case will failed. so we follow a technique using HASHMAP
    // }
    ListNode* removeZeroSumSublists(ListNode* head) {
            unordered_map<int,ListNode*>map; //stores cumulative sum and corresponding node
            // we create a dummy node with element=0 and is assigned at first of list
            ListNode* dummy=new ListNode(0);
            dummy->next=head;
            int sum=0;
            for(ListNode*temp=dummy;temp!=NULL;temp=temp->next){
                sum+=temp->val;
                map[sum]=temp;
            }
        
        // after this our map for testcase 3 i.e,, list 0,1,2,3,-3,-2 will be [(0,0)(1,1)(3,2)(6,3)(3,-3)(1,-2)]
        sum=0;
        for(ListNode*temp=dummy;temp!=NULL;temp=temp->next){
            sum+=temp->val;
            temp->next=map[sum]->next; //map[sum] will give s2nd part of map i.e,, node so node->next in list will taken

        }
        return dummy->next;
        }
};


linkedlist =[0,1,2,-3,3,1]

Cumulative Sum | Node
---------------------
       0        | Node 0 replaced by node -3
       1        | Node 1
       3        | Node 2 replacde by node 3
       4        | Node 1 (last node )

       now we r performinhg this
       for(ListNode*temp=dummy;temp!=NULL;temp=temp->next){
            sum+=temp->val;
            temp->next=map[sum]->next; 
        }


sum=0;
step 1:  our list 0,1,2,-3,3,1
temp is at 0
sum=0 so list is 0->3->1 since temp->next=mp[sum]>next  and temp=temp->next  =  node 3->next =  1

step 2: sum+=1 since temp is at now 1
mp[1] is node 1 and node 1 ka next is null so katham thats it 