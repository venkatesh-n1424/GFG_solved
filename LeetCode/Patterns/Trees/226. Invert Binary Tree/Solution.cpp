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
    void dfs(TreeNode* node){
        if(!node) return;
        TreeNode* t=node->left;
        node->left=node->right;
        node->right=t;
        dfs(node->left);
        dfs(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        //if(!root) return root;
        dfs(root);
        return root;
    }
};