#include<bits/stdc++.h>

using namespace std;

/*//Doing with set will not be good method . bcoz it will give TLE Error since we r fetching for evry subset istead of distinct so its not good way 
class Solution {
public:
    set<vector<int>> ans;

    void helper(int idx, int target, vector<int>& curr, vector<int>& v) {
        if (target == 0) {
            ans.insert(curr);
            return;
        }
        if (idx >= v.size()) return;

        curr.push_back(v[idx]);
        if (v[idx] <= target) {
            helper(idx + 1, target - v[idx], curr, v);
        }
        curr.pop_back();

        helper(idx + 1, target, curr, v);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(0, target, curr, candidates);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};

*/


//Actual METHOD


/*
arr=[1,2,1,1,2]; target=4
sorted = 1,1,1,2,2


Even if i start with index 0 or 1 or 2 will gives us starting with element 1 only .so we will omit the duplicate of starting with same element
so we will get answers=[1,1,2] and [2,2]

also starting with index 3or 4 will also be same 

And also here In this case, the "not take" scenario is implicitly handled by iterating over the elements in the loop.

Therefore, you don’t need to explicitly implement a separate "not take" case in the code;
 the loop itself serves this purpose by advancing to the next index without adding the current element to ds.

*/


class Solution {
public:
    vector<vector<int>> ans;
    void helper(int idx, int target, vector<int>& ds, vector<int>& v) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < v.size(); i++) {
            if (i > idx && v[i] == v[i - 1])
                continue; // we r skipping to start with same elemnet
            if (v[i] > target)
                break;
            ds.push_back(v[i]);
            if (v[i] <= target)
                helper(i + 1, target - v[i], ds, v);
            ds.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        helper(0, target, ds, candidates);
        return ans;
    }
};


