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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> q;
        if(root == nullptr) { return ret; }
        q.push({root, 1});
        while(!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            TreeNode* node = p.first;
            int level = p.second;
            if(level - 1 == ret.size()) {
                ret.push_back({});
            }
            ret[level - 1].push_back(node->val);
            q.pop();
            if(node->left != nullptr) {
                q.push({node->left, p.second + 1});
            } 
            if(node->right != nullptr) {
                q.push({node->right, p.second + 1});
            }
        }
        return ret;
    }
};
