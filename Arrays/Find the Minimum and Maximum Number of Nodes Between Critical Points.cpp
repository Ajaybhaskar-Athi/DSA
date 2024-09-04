//leetcode 2058

#include <bits/stdc++.h> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //less then equals 3 nodes have no possibility of getting 2 critical points
        if(!head || !head->next || !head->next->next || !head->next->next->next)return {-1,-1};
        int pos=2;
        ListNode*post=head->next->next,*curr=head->next,*prev=head;
            vector<int>cps;//critical points
            while(post){
                if(curr->val>post->val && curr->val>prev->val)cps.push_back(pos);
                 else if(curr->val<post->val && curr->val<prev->val)cps.push_back(pos);
                 pos++;
                prev=curr;
                curr=post;
                post=post->next;
                 
            }
            if(cps.size()<2)return {-1,-1};
        int max_dist=cps.back()-cps.front();//largest -smallest 
               int min_dist = INT_MAX;
        for (int i = 1; i < cps.size(); ++i) {
            min_dist = min(min_dist, cps[i] - cps[i - 1]);
        }

        for(int ele:cps)cout<<ele<<" ";
        return {min_dist,max_dist};

    }
};

//Without storing critical points in vector 
//as we already know max distance is 1st criticla point position - last critical point position


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //less then equals 3 nodes have no possibility of getting 2 critical points
        if(!head || !head->next || !head->next->next)return {-1,-1};
        int pos=1;
        ListNode*prev=head;
        ListNode*curr=head->next;
        ListNode*post=curr->next;

        int firstPoint=-1,lastPoint=-1,min_dist=INT_MAX;

            while(post){
                if((curr->val>post->val && curr->val>prev->val) 
                    || (curr->val<post->val && curr->val<prev->val))
                    {
                        if(firstPoint==-1)firstPoint=pos;
                        else min_dist=min(min_dist,pos-lastPoint);
                        lastPoint=pos;
                    }
                 pos++;
                prev=curr;
                curr=post;
                post=post->next;
                 
            }
            if(firstPoint==-1 || (lastPoint==firstPoint))return {-1,-1};
               int max_dist=lastPoint-firstPoint;
        return {min_dist,max_dist};

    }
};





