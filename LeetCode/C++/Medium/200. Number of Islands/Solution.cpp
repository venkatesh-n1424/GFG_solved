class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        function<void(int,int)> dfs=[&](int i,int j){
            if(visited[i][j]) return;
            visited[i][j]=true;
            for(int d=0;d<4;d++){
                int ni=i+dr[d];
                int nj=j+dc[d];
                if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]=='1'){
                    dfs(ni,nj);
                }
            }
        };
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    c++;
                    dfs(i,j);
                }
            }
        }
        return c;
    }
};