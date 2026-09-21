/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool levelEqual(vector<int>& v1,vector<int>& v2){
        if(v1.size()!=v2.size()) return false;
        unordered_map<int,int> mpp;
        for(int& i:v1) mpp[i]++;
        for(int& i:v2){
            if(mpp.find(i)!=mpp.end() && mpp[i]>0){
                mpp[i]--;
            }
            else return false;
        }
        return true;
    }
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        queue<Node*> q1,q2;
        vector<vector<int>> res1,res2;
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty()){
            int s=q1.size();
            vector<int> level;
            while(s--){
                Node* t=q1.front();
                q1.pop();
                level.emplace_back(t->data);
                if(t->left) q1.push(t->left);
                if(t->right) q1.push(t->right);
            }
            res1.push_back(level);
        }
        while(!q2.empty()){
            int s=q2.size();
            vector<int> level;
            while(s--){
                Node* t=q2.front();
                q2.pop();
                level.emplace_back(t->data);
                if(t->left) q2.push(t->left);
                if(t->right) q2.push(t->right);
            }
            res2.push_back(level);
        }
        if(res1.size()!=res2.size()) return false;
        int n=res1.size();
        for(int i=0;i<n;i++){
            if(!levelEqual(res1[i],res2[i])) return false;
        }
        return true;
    }
};
