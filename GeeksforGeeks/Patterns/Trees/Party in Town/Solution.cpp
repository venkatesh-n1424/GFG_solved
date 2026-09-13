class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj,int start){
        int n=adj.size();
        vector<int> dist(n+1,-1);
        queue<int> q;
        q.push(start);
        dist[start]=0;
        int farthestnode=start;
        int farthestdist=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int next:adj[node-1]){
                if(dist[next]==-1){
                    dist[next] = dist[node]+1;
                    q.push(next);
                    if(dist[next]>farthestdist){
                        farthestdist=dist[next];
                        farthestnode=next;
                    }
                }
            }
        }
        return vector<int>{farthestnode,farthestdist};
    }
    int partyHouse(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        if(n==1) return 0;
        // find one end of diameter
        vector<int> first = bfs(adj,1);
        int farthestnode = first[0];
        //find diameter lenght
        vector<int> second = bfs(adj,farthestnode);
        int diameter = second[1];
        return (diameter+1)/2;
    }
};