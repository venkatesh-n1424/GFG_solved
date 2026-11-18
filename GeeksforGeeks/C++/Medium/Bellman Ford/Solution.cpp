class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dis(V,1e8);
        dis[src]=0;
        for(int i=1;i<V;i++){
            for(auto& e:edges){
                if(dis[e[0]]!=1e8 && dis[e[0]]+e[2]<dis[e[1]]){
                    dis[e[1]]=dis[e[0]]+e[2];
                }
            }
        }
        for(auto& e:edges){
                if(dis[e[0]]!=1e8 && dis[e[0]]+e[2]<dis[e[1]]){
                    return vector<int>{-1};
                }
            }
        return dis;
    }
};
