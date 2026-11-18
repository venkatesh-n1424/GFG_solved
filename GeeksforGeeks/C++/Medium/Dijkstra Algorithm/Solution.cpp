class Solution {
  public:
    vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
        // Code here
        int V=adj.size();
        vector<int> dis(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            pair<int,int> t=pq.top();
            int d=t.first,node=t.second;
            pq.pop();
            if (d > dis[node]) continue;
            for(auto& v:adj[node]){
                if(v[1]+d<dis[v[0]]){
                    dis[v[0]]=v[1]+d;
                    pq.push({dis[v[0]],v[0]});
                }
            }
        }
        return dis;
    }
};