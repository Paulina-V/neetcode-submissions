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
    int totalCount = 0;
    int goodNodes(TreeNode* root) {
        int maxSeen = -101;
        if (root) {
            dfs(root, maxSeen);
        }
        return totalCount;
    }
    void dfs(TreeNode* root, int maxSeen) {
        cout << "root:" << root->val << " maxSeen:" << maxSeen << "\n";
        if(!root) return;
        if(root->val >= maxSeen) {
            totalCount++;
            maxSeen = root->val;
            cout << "yes\n";
        } 
        if(root->left) dfs(root->left, maxSeen);
        if(root->right) dfs(root->right, maxSeen);
    }
};
