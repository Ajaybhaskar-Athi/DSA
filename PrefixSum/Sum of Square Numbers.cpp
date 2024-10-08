/*Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        set<int>s;
        int limit=sqrt(c);
        for(int i=0;i<=limit;i++){
            s.insert(i*i);
            if(s.find(c-i*i)!=s.end())return true;
        }
        return false;
    }
};