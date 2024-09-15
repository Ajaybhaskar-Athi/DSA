#include <bits/stdc++.h>
using namespace std;
class Node
{
    Node *links[26];
    bool flag;

public:
    Node(){
        flag=false;
        for(auto &a:links)a=nullptr;
    }

    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch ,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }

};



int countDistinctSubstrings(string &s){

        Node*root=new Node();
        int cnt=0;
    for(int i=0;i<s.length();i++){
            Node*node=root;
        for(int j=i;j<s.length();j++){
            if(!node->containsKey(s[j])){
                node->put(s[j],new Node());
                cnt++;
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1;
}