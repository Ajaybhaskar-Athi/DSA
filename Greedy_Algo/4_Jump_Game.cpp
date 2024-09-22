#include <bits/stdc++.h>
using namespace std;

// Greedy
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > maxIndex)
                return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }

    //TC=O(n)
};

// DP

class Solution
{
public:
    bool helper(int idx, vector<int> &nums)
    {
        if (idx >= nums.size() - 1)
            return true;
        if (nums[idx] == 0)
            return false; // if we reaches elemnt 0 then u r stucked

        int reach = idx + nums[idx];
        for (int i = idx + 1; i <= reach; i++)
        {
            if (i < nums.size() && helper(i, nums))
                return true;
        }
        return false;
    }

    bool canJump(vector<int> &nums)
    {
        return helper(0, nums);
    }

    //TC=O(n**2);
};

/*

For the Jump Game problem, the Greedy method is generally preferred over Dynamic Programming (DP) due to its simplicity and efficiency. Here's why:

Time Complexity:

Greedy: It runs in O(n) time, where n is the length of the array, because you only need to make a single pass through the array to track the farthest position you can reach.
DP with memoization: Although memoization improves over simple recursion, it still has an overhead of maintaining a state table and has a complexity of O(n^2) due to exploring all possible jumps from each index.
Space Complexity:

Greedy: It uses constant extra space, O(1).
DP: It requires O(n) space for the memoization table.
Simplicity: The greedy approach is straightforward. You just need to track the farthest index you can jump to and check if it reaches or exceeds the last index.
*/