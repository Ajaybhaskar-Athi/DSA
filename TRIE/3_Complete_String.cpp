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

class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }


        void insert(string word){
            Node*node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                        node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
        }

    
    bool isPrefixExists(string sr){
        bool f=true;
        Node*node=root;
        for(int i=0;i<sr.length();i++){
            if(node->containsKey(sr[i])){
                node=node->get(sr[i]);
                //check if its reference is having prefix or not
                if(node->isEnd()==false)return false;
            }
           else  return false;
        }
        return true;
    }
};


    string completeString(int n,vector<string>&a){
        Trie trie;
        for(auto &it:a){
            trie.insert(it);
        }

        string longest="";
        for(auto &it:a){
            if(trie.isPrefixExists(it)){
                if(it.length()>longest.length()){
                    longest=it;
                }
                else if(it.length()==longest.length( ) && it<longest){
                    longest=it;
                    //lexicograhical small when two complete strings are of same length
                }
            }
        }
        if(longest=="")return "None";
        return longest;
    }



