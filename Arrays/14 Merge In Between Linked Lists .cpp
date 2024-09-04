
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* mergeInBetween(ListNode* h1, int a, int b, ListNode* h2) {
        ListNode*temp=h1;
        int c=b-a;
        while(a>1){
            temp=temp->next;
            a--;
        }
        ListNode*temp2=temp->next;
        for(int i=0;i<c;i++)temp2=temp2->next;
    ListNode*temp3=h2;
while(temp3->next!=NULL)temp3=temp3->next;
        temp->next=h2;
        temp3->next=temp2->next;
        return h1;

    }
};