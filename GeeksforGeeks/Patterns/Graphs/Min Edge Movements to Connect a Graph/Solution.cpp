class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        int m=edges.size();
        if(m<n-1) return -1;
        vector<vector<int>> adj(n);
        for(const auto& e:edges){
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<bool> visit(n,false);
        int components=0,extraedges=0;
        for(int i=0;i<n;i++){
            if(visit[i]) continue;
            components++;
            int vertices=0,edgescount=0;
            queue<int> q;
            q.push(i);
            visit[i]=true;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                vertices++;
                edgescount+=adj[node].size();
                for(int next:adj[node]){
                    if(!visit[next]){
                        visit[next]=true;
                        q.push(next);
                    }
                }
            }
            int actualEdges=edgescount/2;
            extraedges+=actualEdges-vertices+1;
        }
        int req=components-1;
        if(extraedges>=req) return req;
        return -1;
    }
};