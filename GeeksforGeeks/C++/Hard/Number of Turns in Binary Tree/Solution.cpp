/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* lca(Node* root,int p,int q){
        if(!root || root->data==p || root->data==q) return root;
        
        Node* lt=lca(root->left,p,q);
        Node* rt=lca(root->right,p,q);
        if(!lt) return rt;
        if(!rt) return lt;
        return root;
    }
    bool findPath(Node* root,int tar,string& path){
        if(!root) return false;
        if(root->data==tar) return true;
        path.push_back('L');
        if(findPath(root->left,tar,path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');
        if(findPath(root->right,tar,path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        Node* L = lca(root,p,q);
        string a,b;
        findPath(L,p,a);
        findPath(L,q,b);
        
        reverse(a.begin(),a.end());
        string tot=a+b;
        int c=0,i=1;
        while(i<tot.size()){
            if(tot[i]!=tot[i-1]){
                c++;
            }
            i++;
        }
        if(c==0) return -1;
        return c;
    }
};