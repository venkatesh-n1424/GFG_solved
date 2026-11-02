class Solution {
  public:
    vector<int>vis;
    vector<int>parent;
    vector<int>temp;
    int dfs(vector<int>adj[], int node, int par){
        vis[node]=1;
        parent[node]=par;
        temp.push_back(node) ;
        for(auto child:adj[node]){
    
        if(vis[child] == 0){
    
        int cycle=dfs(adj,child,node);
        if(cycle !=- 1)
    
            return cycle;
        }
    
        else if(vis[child] == 1)
        {
    
        int sum=child;
        while(node != child){
    
        sum+=node;
        node=parent[node];
        }
    
        return sum;
        }
        }
        return -1;
    }
    
    int largestSumCycle(vector<int>& edge) {
        // code here
        int N=edge.size();
        vis=vector<int>(N,0);
        parent=vector<int>(N,-1);

        vector<int>adj[N];

        for(int i=0;i<N; i++){

            if(edge[i] !=- 1)
                adj[i].push_back(edge[i]);
        }
        int ans=-1;
        for(int i=0;i<N;i++){
            if(!vis[i]) ans=max(ans,dfs(adj,i,-1));
            for(auto nd:temp){
                vis[nd]=2;
            }
            temp.clear();
        }
        return ans;
    }
};