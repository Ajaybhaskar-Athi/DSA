#pragma GCC optimize("O3", "unroll-loops")
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
        ListNode*findMid(ListNode*head){
            ListNode*slow=head;
            ListNode*fast=head->next;

            //THE ONLY DIFF B/W TORTOISE AND HARY and here is we moving fast to 2nd element head->next at starting
            //since we want mid such that it will be the 1st mid .suppose in even length we got mid=3rd pos by tortoise and hary 
            //but here in msort we r taking 1st head has high values then 2nd head
            while(fast && fast->next){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }
        /*
          ListNode*findMid(ListNode*head){
        ListNode*s=head,*f=head;
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    } //try normal to0rtois and harre mathod also its also worked in leetcode
    */

        ListNode*merge(ListNode*h1,ListNode*h2){
            //MERGING two sorted linked lists 
            if(!h1 || !h2){
                return h1==NULL?h2:h1;
            }
            ListNode*fh=new ListNode(-1);
            ListNode*ft=fh;

            ListNode*t1=h1;
            ListNode*t2=h2;
            while(t1 && t2){
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
                //but we do know that in this merge sort 1st head is having more no of values 
                // then 2nd list(since left->mid and mid+1->rigth so if if even=4 we got 1st mid=pos 1 if odd=5 we got 1stmid=3)
                //  since we divide in that way 
            }
            return fh->next;

        }
    ListNode* sortList(ListNode* head) {
           if(!head ||!head->next)return head;

           ListNode*mid=findMid(head);  

            ListNode*leftHead=head;
            ListNode*rightHead=mid->next;

            mid->next=NULL;//seperate the lists

           leftHead= sortList(leftHead); //since it returns the sorted head and we r storing in the leftHEad
            rightHead=sortList(rightHead);

            return merge(leftHead,rightHead);//merging the two sorted lists;
           
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();