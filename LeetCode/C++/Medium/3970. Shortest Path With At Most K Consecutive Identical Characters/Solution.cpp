class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX));
        dist[0][1]=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        q.push({0,0,1});//w,node,streak
        while(!q.empty()){
            vector<int> t=q.front();
            q.pop();
            if(t[0]>dist[t[1]][t[2]]) continue;
            if(t[1]==n-1) return t[0];
            for(auto& ne:adj[t[1]]){
                int nei=ne.first;
                int wt=ne.second;
                int ns;
                if(labels[t[1]]!=labels[nei]) ns=1;
                else ns=t[2]+1;
                if(ns>k) continue;
                if(dist[nei][ns]>t[0]+wt){
                    dist[nei][ns]=t[0]+wt;
                    q.push({t[0]+wt,nei,ns});
                }
            }
        }
        return -1;
    }
};