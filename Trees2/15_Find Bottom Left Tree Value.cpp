/*Given the root of a binary tree, return the leftmost value in the last row of the tree.
Example 1

Input: root = [2,1,3]
Output: 1
Example 2:
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 
Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/



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
    
    void helper(TreeNode*root,int& ans,int curLevel,int& maxLevel){
        if(!root)return;
        if(curLevel>maxLevel){
            ans=root->val;
            maxLevel=curLevel;
        }
        helper(root->left,ans,curLevel+1,maxLevel);
        helper(root->right,ans,curLevel+1,maxLevel);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=-1;
        int curLevel=0;
        int maxLevel=-1;
        helper(root,ans,curLevel,maxLevel);
        return ans;
    }
};