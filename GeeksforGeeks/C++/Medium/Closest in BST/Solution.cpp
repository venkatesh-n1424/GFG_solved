/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int minDiff(Node *root, int k) {
        //TC-O(height)
        // code here
        int dif=INT_MAX;
        function<int(Node*)> solve=[&](Node* node){
            if(!node) return dif;
            dif=min(dif,abs(k-node->data));
            if(k<node->data) return solve(node->left);
            return solve(node->right);
        };
        return solve(root);
    }
};
