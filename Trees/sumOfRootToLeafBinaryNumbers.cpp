/*You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

 

Example 1:


Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
Example 2:

Input: root = [0]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.*/


#include<bits/stdc++.h>
using namespace std;
#include<vector>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  

 class Solution {
public:
    void rootToLeaf(TreeNode* root, string currentString, int &ans) {
        if (!root) return;
        currentString += to_string(root->val);
        
        // If it's a leaf node, convert the binary string to an integer and add to the answer
        if (!root->left && !root->right) {
            ans += stoi(currentString, nullptr, 2); //Strinng cobverted to integers in decimal form 
            //if i write stoi(currentString,nullptr,10) it will convert the string as it is into number i,e.. in 10's form . so if string="10101" then ans=10101 if we do this

            return;
        }
        if (root->left) rootToLeaf(root->left, currentString, ans);//we can omit if condition also coz in case if theres no left root it goes to base condtion and return
        if (root->right) rootToLeaf(root->right, currentString, ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        rootToLeaf(root, "", ans);
        return ans;
    }
};