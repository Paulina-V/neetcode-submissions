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
private: 
    bool balBool = true; 

public:
    bool isBalanced(TreeNode* root) {
        countHeights(root);
        return balBool;
    }
    
    int countHeights(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftH = countHeights(root -> left);
        int rightH = countHeights(root -> right);
        if (abs(leftH - rightH) > 1) balBool = false;
        return 1 + max(leftH, rightH);
    }
};
