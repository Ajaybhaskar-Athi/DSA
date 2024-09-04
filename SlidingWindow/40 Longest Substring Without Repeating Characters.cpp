Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

            unordered_set<char>st;
    int l=0,r=0,res=0;
    int n=s.size();
    while(r<n){
        if(!st.count(s[r])){
            st.insert(s[r]);
            r++;
        }

        else{
            st.erase(s[l]);
            l++;
        }
        res=max(res,r-l);
    }
    return res;

    }
}



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        for(int i=0;i<=256;i++)mp[i]=-1;
        int l=0,r=0,maxlen=0,n=s.size();
        while(r<n){
            if(mp[s[r]]!=-1){
                if(mp[s[r]]>=l){
                    l=mp[s[r]]+1; // left move to previous index of duplicate element +1 
                    
                }
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            mp[s[r]]=r;
            r++;
        }
        return maxlen;
        
    }
};


tc=O(N);
sc=O(256);