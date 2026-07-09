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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if p and q both < root --> the LCA is in the left subtree
        // if p and q both > root --> the LCA is in the right subtree
        // else the root is between p and q or equal to one of them, so root is the LCA
        
        while (root != nullptr) {
            if(p->val < root-> val && q->val < root->val) {
                root = root->left; 
            } else if (p->val > root-> val && q->val > root->val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};
