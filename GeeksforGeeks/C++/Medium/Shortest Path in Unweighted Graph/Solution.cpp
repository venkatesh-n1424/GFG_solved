class Solution {
  public:
    int shortestPath(vector<vector<int>> &adj, int src, int dest) {
        // code here
        int V=adj.size();
        vector<int> dis(V,1e9);
        dis[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(auto& v:adj[t]){
                if(dis[t]+1<dis[v]){
                    dis[v]=dis[t]+1;
                    q.push(v);
                }
            }
        }
        return dis[dest]==1e9 ? -1: dis[dest];
    }
};
