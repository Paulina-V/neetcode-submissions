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
    int preInd = 0;
    int inInd = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // pre order = root, left, right
        // the root is the 0th node in preorder
        // since all nodes are unique if u find the preorder[0] node in the inorder one then you know what's on the left vs right

        return dfs(preorder, inorder, INT_MAX);
    }

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int lim) {
        if(preInd >= preorder.size()) return nullptr;
        if(inorder[inInd] == lim) {
            inInd++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preInd++]);
        root->left = dfs(preorder, inorder, root->val);
        root->right = dfs(preorder, inorder, lim);
        return root;
        
    }
};

