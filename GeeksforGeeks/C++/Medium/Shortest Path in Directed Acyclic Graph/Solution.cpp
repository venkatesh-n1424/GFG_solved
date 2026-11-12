class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        //TC-(V+edges) Sc-O(V)
        vector<vector<vector<int>>> adj(V);
        for(auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<int> vis(V,0);
        stack<int> st;
        function<void(int)> dfs=[&](int i){
            vis[i]=1;
            for(auto& v:adj[i]){
                if(!vis[v[0]]) dfs(v[0]);
            }
            st.push(i);
        };
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i);
        }
        vector<int> dis(V,1e9);
        dis[0]=0;
        while(!st.empty()){
            int t=st.top();
            st.pop();
            for(auto& v:adj[t]){
                if(dis[t]+v[1]<dis[v[0]]){
                    dis[v[0]]=dis[t]+v[1];
                }
            }
        }
        for(int i=1;i<V;i++){
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
};
