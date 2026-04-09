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
        return fun(root, LONG_MIN, LONG_MAX);
    }

    bool fun(TreeNode* root, long minVal, long maxVal){
        if(!root)return true;

        if(root->val <= minVal || root->val >= maxVal)return false;

        return fun(root->left, minVal, root->val) && fun(root->right, root->val, maxVal);
    }
};
