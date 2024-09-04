Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true



mehtod 1:

usinhg hashing 


Mapping Characters: 
                        We are traversing both input strings, 's' and 't', in parallel. 
For each character at a given position, we are mapping the character from 's' to its corresponding character in 't' and vice versa.
 This mapping is stored in two separate unordered_maps: StoT to map characters from 's' to 't', and TtoS to map characters from 't' to 's'.

Checking Isomorphism: 
                    During the traversal, we then check if the characters at the same index in the two strings follow the established mapping. 
If a character in 's' maps to a different character in 't' than expected, or vice versa, then the strings are not isomorphic.
 This helps ensure that each character is consistently mapped to the same corresponding character in the other string.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
     unordered_map<char,char>StoT;
     unordered_map<char,char>TtoS;
if(s.size()!=t.size()) return false;
if(s.size()==1)return true;
        for(int i=0;i<s.size();i++){
            char sc=s[i];
            char tc=t[i];
            if(StoT.find(sc)==StoT.end()){
                    StoT[sc]=tc;
            }
            else {
                if(StoT[sc]!=tc)return false;
            }

            if(TtoS.find(tc)==TtoS.end()){
                TtoS[tc]=sc;
            }
            else{
                if(TtoS[tc]!=sc)return false;
            }
        }  
        return true; 
    }
};



method 2 :
we can aslo do this by arrays with same above time complexity O(N)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(200, 0); // Stores index of characters in string s
        vector<int> indexT(200, 0); // Stores index of characters in string t
        
        int len = s.length(); // Get the length of both strings
        
        if(len != t.length()) { // If the lengths of the two strings are different, they can't be isomorphic
            return false;
        }
        
        for(int i = 0; i < len; i++) { // Iterate through each character of the strings
            if(indexS[s[i]] != indexT[t[i]]) { // Check if the index of the current character in string s is different from the index of the corresponding character in string t
                return false; // If different, strings are not isomorphic
            }
            
            indexS[s[i]] = i + 1; // updating position of current character
            indexT[t[i]] = i + 1;
        }
        
        return true; // If the loop completes without returning false, strings are isomorphic
    }
};