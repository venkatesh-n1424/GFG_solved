class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        set<pair<int,int>> seen;
        int res=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        function<long long(int,int)> dfs=[&](int i,int j){
            if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || seen.find(make_pair(i,j))!=seen.end()) return (long long)0;
            seen.insert(make_pair(i,j));
            long long sum=grid[i][j];
            for(int d=0;d<4;d++){
                sum+=dfs(i+dr[d],j+dc[d]);
            }
            return sum;
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 && seen.find(make_pair(i,j))==seen.end()){
                    long long total_val=dfs(i,j);
                    if(total_val%k==0) res++;
                }
            }
        }
        return res;
    }
};