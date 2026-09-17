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
    int maxi=0;
    int findlh(TreeNode* node){
        if(node==nullptr) return 0;
        return 1+max(findlh(node->left),findlh(node->right));
    }
    int findrh(TreeNode* node){
        if(node==nullptr) return 0;
        return 1+max(findrh(node->right),findrh(node->left));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=findlh(root->left);
        int rh=findrh(root->right);
        maxi=max(maxi,rh+lh);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
};