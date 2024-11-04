
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

        unordered_set<string>validSet; //only distinct elements

        void helper(int idx,string s,int leftRemoval,int rightRemoval,int leftAdded,int rightAdded,string curr_s){
                if(idx==s.size()){
                    if(leftRemoval==0 && rightRemoval==0){
                        validSet.insert(curr_s);
                        return;
                    }
                }

                if(leftAdded<rightAdded) return;//not valid string
                if(s.size()-idx < leftRemoval+rightRemoval) return;//if remaining elements  are less then removing count :terminate earlier



            if(s[idx]=='(' && leftRemoval){
                helper(idx+1,s,leftRemoval-1,rightRemoval,leftAdded,rightAdded,curr_s);
            }
            if(s[idx]==')' && rightRemoval){
                helper(idx+1,s,leftRemoval,rightRemoval-1,leftAdded,rightAdded,curr_s);
            }

            int left=s[idx]=='(' ?1:0;
            int right=s[idx]==')'?1:0;

            helper(idx+1,s,leftRemoval,rightRemoval,leftAdded+left,rightAdded+right,curr_s+s[idx]);



        }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemoval = 0, rightRemoval = 0; // left Removal And Right Removal
        for (char c : s) {
            if (c == '(')
                leftRemoval++;
            else if (c == ')') {
                if(leftRemoval)leftRemoval--;
                else rightRemoval++;
            }
        }

        helper(0,s,leftRemoval,rightRemoval,0,0,"");

        return vector<string>(validSet.begin(),validSet.end());
    }   
};
