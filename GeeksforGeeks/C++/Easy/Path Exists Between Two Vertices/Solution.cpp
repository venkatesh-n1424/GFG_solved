class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        // code here
        bool res=false;
        vector<int> vis(adj.size(),false);
        function<void(int)> dfs=[&](int i){
            vis[i]=true;
            if(i==v) {
                res=res||true;
                return;
            }
            for(auto& n:adj[i]){
                if(!vis[n]) dfs(n);
            }
        };
        dfs(u);
        return res;
    }
};