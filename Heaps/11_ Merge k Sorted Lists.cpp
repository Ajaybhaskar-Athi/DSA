#include<bits/stdc++.h>
using namespace std;



//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i=0;i<lists.size();i++){
            ListNode*h=lists[i];
            while(h){
                pq.push({h->val,h});
                h=h->next;
            }
        }

        ListNode*nn=new ListNode(-1);
        ListNode*tail=nn;
        while(!pq.empty()){
            tail->next=pq.top().second;
            tail=tail->next;
            pq.pop();
        }
        return nn->next;

    }
};