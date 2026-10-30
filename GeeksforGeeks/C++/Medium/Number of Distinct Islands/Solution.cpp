class Solution {
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        set<vector<pair<int,int>>> di;
        pair<int,int> base;
        vector<pair<int,int>> res;
        function<void(int,int)> dfs=[&](int i,int j){
                if(vis[i][j]) return;
                vis[i][j]=true;
                res.push_back({i-base.first,j-base.second});
                for(int d=0;d<4;d++){
                       int ni=i+dr[d];
                       int nj=j+dc[d];
                       if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='L')
                           dfs(ni,nj);
                   }
        };
              for(int i=0;i<n;i++){
                   for(int j=0;j<m;j++){
                       if(grid[i][j]=='L' && !vis[i][j]){
                           base=make_pair(i,j);
                           res.clear();
                           dfs(i,j);
                           di.insert(res);
                       }
                   }
               }
               return di.size();
    }
};
