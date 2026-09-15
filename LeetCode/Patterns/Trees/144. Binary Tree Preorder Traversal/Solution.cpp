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
    vector<int> res;
    void pot(TreeNode* root){
        if(!root) return;
        res.emplace_back(root->val);
        pot(root->left);
        pot(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        pot(root);
        return res;
    }
};