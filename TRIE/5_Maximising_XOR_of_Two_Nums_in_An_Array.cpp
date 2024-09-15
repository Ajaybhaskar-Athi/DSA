    #include <iostream>
    #include <vector>

    using namespace std;
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
        int findMaximumXOR(vector<int>& nums) {
                Trie trie;
                for(auto&it:nums){
                    trie.insert(it);
                }
                int maxi=0;
                for(auto &it:nums){
                    // cout<<it<<" "<<trie.getMax_XOR(it)<<endl;
                    maxi=max(maxi,trie.getMax_XOR(it));
                }
                return maxi;
        }
    };