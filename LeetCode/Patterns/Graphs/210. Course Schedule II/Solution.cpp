class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Topo sort
        vector<vector<int>> adj(numCourses);
        for(auto& e: prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ind(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto& v:adj[i]){
                ind[v]++;
            }
        }
        queue<int> q;
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(!ind[i]) q.push(i);
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            res.emplace_back(t);
            for(auto& v:adj[t]){
                ind[v]--;
                if(!ind[v]) q.push(v);
            }
        }
        if(res.size()==numCourses) return res;
        return vector<int>{};
    }
};