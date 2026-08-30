/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return recurse(root, -1001, 1001);
    }
    bool recurse(TreeNode* node, int min, int max) {
        if(!node) return true;
        if(node->val <= min || node ->val >= max) { 
            return false;
        }
        return recurse(node->left, min, node->val) && recurse(node->right, node->val, max);
    }

    

    
};
