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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int maxD = 0;
        while(!s.empty()) {
            pair<TreeNode*, int> p = s.top();
            s.pop();
            maxD = max(maxD, p.second);
            if(p.first->left) s.push({p.first->left, p.second + 1});
            if(p.first->right) s.push({p.first->right, p.second + 1});
        }
        return maxD;
    }
};
