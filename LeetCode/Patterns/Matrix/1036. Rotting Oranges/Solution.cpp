class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int t=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        function<void(int,int)> bfs=[&](int i,int j){
            queue<vector<int>> q;
            q.push({i,j,t});
            while(!q.empty()){
                vector<int> temp=q.front();
                q.pop();
                t=temp[2];
                for(int d=0;d<4;d++){
                    int ni=i+dr[d];
                    int nj=j+dc[d];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj,temp[2]+1});
                    }
                }
            }
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) bfs(i,j);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) if(grid[i][j]==1) return -1;
        }
        return t;
    }
};