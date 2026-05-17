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
    vector<TreeNode*> heightVals;
    vector<int> ret;
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        // reverse in order traversal, so basically dfs from the end to the beggining, and store those nodes in a vector correspondingg to the height that it's at 
        // then as we loop through the rest of the tree, check if there is something stored in the vector for that height and if not, then we can print that one and add it to the vector, otherwise we just by pass it because it would be one that's blocked. 
        getRightMostPerHeight(root, 0);
        ret.push_back(root->val);
        for(auto& item : heightVals) {
            ret.push_back(item->val);
        }
        return ret;
    }
    
    // this should populate the heightVals;
    void getRightMostPerHeight(TreeNode* root, int h) {
        if(!root) return;
        if(heightVals.size() < h) { // there nothing already at this height
            heightVals.push_back(root);
        }
        if(root->right) getRightMostPerHeight(root->right, h+1);
        if(root->left) getRightMostPerHeight(root->left, h+1);
    }
};
