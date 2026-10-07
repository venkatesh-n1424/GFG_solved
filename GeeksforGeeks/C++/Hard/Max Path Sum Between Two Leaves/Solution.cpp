/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    int ans,lc;
    int dfs(Node* root){
        if(!root->left && !root->right){
            lc++;
            return root->data;
        }
        if(!root->left) return root->data+dfs(root->right);
        if(!root->right) return root->data+dfs(root->left);
        int left=dfs(root->left);
        int right=dfs(root->right);
        ans=max(ans,left+root->data+right);
        return root->data+max(left,right);
    }
    int maxPathSum(Node *root) {
        // code here
        if(!root) return -1;
        ans=INT_MIN;
        lc=0;
        dfs(root);
        if(lc<2) return -1;
        return ans;
    }
};