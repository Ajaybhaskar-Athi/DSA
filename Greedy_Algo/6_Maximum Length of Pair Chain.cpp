#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
class Solution {
public:
    bool static compareSort(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), compareSort);
        int count = 1;
        int prevEnd = v[0][1];
        for (auto ele : v) {
                if (ele[0]> prevEnd) {
                    count++;
                    prevEnd = ele[1];
                }
            
        }
        return count;
    }
};
