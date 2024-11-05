#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void helper(int idx, int target, vector<int>& ds, vector<int>& v) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (idx >= v.size()) return;
        ds.push_back(v[idx]);
        if (v[idx] <= target) helper(idx, target - v[idx], ds, v);
        ds.pop_back();
        helper(idx + 1, target, ds, v);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        helper(0, target, ds, candidates);
        return ans;
    }
};
