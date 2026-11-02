class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        int vis[n];
        memset(vis, 0, n * sizeof(int));
        //0->not visited
        //1->visited
        //2->visited and path visited
        vector<vector<int>> adj(n);
        for(auto& e:prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        function<bool(int)> dfs=[&](int i){
            vis[i]=2;
            for(auto& j:adj[i]){
                if(!vis[j]){
                    if(dfs(j)) return true;
                }
                else if(vis[j]==2) return true;
            }
            vis[i]=1;
            return false;
        };
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i)) return false;
            }
        }
        return true;
    }
};