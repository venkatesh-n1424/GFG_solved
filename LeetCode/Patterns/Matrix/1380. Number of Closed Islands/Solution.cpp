class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int res=0;
        bool closed;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        set<pair<int,int>> seen;
        function<void(int,int)> dfs=[&](int i,int j){
            if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==1 || seen.find(make_pair(i,j))!=seen.end()) return;
            if(i==0 || i==n-1 || j==0 ||j==m-1) closed=false;
            seen.insert(make_pair(i,j));
            for(int k=0;k<4;k++){
                dfs(i+dr[k],j+dc[k]);
            }

        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                closed=true;
                if(grid[i][j]==0 && seen.find(make_pair(i,j))==seen.end()){
                    dfs(i,j);
                    if(closed) res++;
                }
            }
        }
        return res;
    }
};