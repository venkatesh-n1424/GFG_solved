class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //Tc-O(mn) sc-O(mn)
        int m=grid.size(),n=grid[0].size();
        int t=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        int cntFresh=0;
        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j,0});
                if(grid[i][j]==1) cntFresh++;
            }
        }
        int cnt=0;
            while(!q.empty()){
                vector<int> temp=q.front();
                q.pop();
                t=max(t,temp[2]);
                for(int d=0;d<4;d++){
                    int ni=temp[0]+dr[d];
                    int nj=temp[1]+dc[d];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj,temp[2]+1});
                        cnt++;
                    }
                }
            }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++) if(grid[i][j]==1) return -1;
        // }
        if(cnt!=cntFresh) return -1;
        return t;
    }
};