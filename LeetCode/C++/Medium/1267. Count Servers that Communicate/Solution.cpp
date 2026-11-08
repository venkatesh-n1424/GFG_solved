class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};
        function<int(int,int)> bfs=[&](int i,int j){
            vis[i][j]=1;
            int cnt=1;
            queue<pair<int,int>> q;
            q.push({i,j});
            while(!q.empty()){
                pair<int,int> t=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int ni=t.first+dr[d];
                    int nj=t.second+dc[d];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        if(!vis[ni][nj]){
                            vis[ni][nj]=1;
                            q.push({ni,nj});
                            cnt++;
                        }
                    }
                }
            }
            return cnt;
        };
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !vis[i][j]){
                    int cnt=bfs(i,j);
                    if(cnt>1) res+=cnt;
                }
            }
        }
        return res;
    }
};