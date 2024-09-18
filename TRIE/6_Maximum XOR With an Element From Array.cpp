#include<bits/stdc++.h>
using namespace std;

//BrutForce: O(q * n);


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
            vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int xi=queries[i][0];
            int ai=queries[i][1];   
            int maxXor=-1;
            for(int j=0;j<nums.size();j++){
                if(nums[j]<=ai){
                    maxXor=max(maxXor,nums[j]^xi);
                }
            }
            ans.push_back(maxXor);

        }
        return ans;
    }
};



//Using Tries



//Thi is Simply u r given an array and u need to tell max[ele]^x;
class Node{
    //to store two bits 0/1
    Node*links[2];
    bool flag;

    public:

    Node(){
        flag=false;
        for(auto&it:links)it=nullptr;
    }
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node*get(int bit){
        return links[bit];
    }
    void put(int bit,Node*node){
        links[bit]=node;

    }
    

};

class Trie{

    Node*root;
        public:
    Trie(){
        root=new Node();
    }


    void insert(int num){
        Node*node=root;
        for(int i=31;i>=0;i--){
            //perfoming AND Op^n with ith bit ,1 gives that ith is set or not 
            int bit=(num>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
        }
    }

    int getMax_XOR(int num){
        Node*node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            //finding opposite bit
            if(node->containsKey(1-bit)){
                //opp bit exist means result is 1;
                maxNum=maxNum | (1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return maxNum;
    }

};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
            vector<int>ans(queries.size(),-1);
            vector<pair<int,pair<int,int>>> offline_queries; //mi{xi,index}
            int idx=0;
            for(auto&it:queries){
                offline_queries.push_back( { it[1], {it[0],idx++} });
            }   
            //sorting acc to mi (endpoint)
            sort(offline_queries.begin(),offline_queries.end());
            //sort given array too
            sort(nums.begin(),nums.end());

            int maxi=0;
            int i=0;
            int n=nums.size();
            Trie trie;
            for(auto&it:offline_queries){

                while(i<n && nums[i]<=it.first){
                    trie.insert(nums[i++]);
                }
                if(i!=0){
                    ans[it.second.second]=trie.getMax_XOR(it.second.first);
                }
            }

        return ans;
    }
};
