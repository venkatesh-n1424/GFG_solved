/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*,Node*> otn;
        function<Node*(Node*)> dfs=[&](Node* cur){
            if(otn.find(cur)!=otn.end()){
                return otn[cur];
            }
            Node* dnode=new Node(cur->val);
            otn[cur]=dnode;
            for(auto& nei:cur->neighbors){
                dnode->neighbors.push_back(dfs(nei));
            }
            return dnode;
        };
        return dfs(node);   
    }
};