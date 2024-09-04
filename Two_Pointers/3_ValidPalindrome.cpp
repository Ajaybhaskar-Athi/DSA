#include<bits/stdc++.h>
using namespace std;

/*
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
         while(i<j){
            if(!isalnum(s[i])){i++; continue;}
            if(!isalnum(s[j])){ j--; continue;} //is its not an alphanumeric not compare just continue
            if(tolower(s[i])!=tolower(s[j]))return false;
            i++;
            j--;
        }
        return true;
    }
};