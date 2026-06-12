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
    int goodNodes(TreeNode* root) {
        int maxi = root->val;
        int good = 0;
        dfs(root, good, maxi);
        return good;
    }

    void dfs(TreeNode* root, int&good, int maxi){
        if(root==NULL)return;

        if(maxi <= root->val){
            maxi = root->val;
            good++;
        }

        dfs(root->left, good, maxi);
        dfs(root->right, good, maxi);
    }
};
