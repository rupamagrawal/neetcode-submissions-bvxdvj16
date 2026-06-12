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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            TreeNode* node = que.front(); que.pop();
            if(node->val == subRoot->val && isSameTree(node, subRoot))return true;
            if(node->left)que.push(node->left);
            if(node->right)que.push(node->right);
        }

        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL)return p==q;

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
