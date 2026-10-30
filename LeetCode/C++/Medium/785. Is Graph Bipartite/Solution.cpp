class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        function<bool(int)> bfs=[&](int i){
            queue<int> q;
            q.push(i);
            vis[i]=0;
            while(!q.empty()){
                int t=q.front();
                q.pop();
                for(auto& j:graph[t]){
                    if(vis[j]==-1){
                        q.push(j);
                        if(vis[t]==0) vis[j]=1;
                        else vis[j]=0;
                    }
                    else{
                        if(vis[t]==vis[j]) return false;
                    }
                }
            }
            return true;
        };
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!bfs(i)) return false;
            }
        }
        return true;
    }
};