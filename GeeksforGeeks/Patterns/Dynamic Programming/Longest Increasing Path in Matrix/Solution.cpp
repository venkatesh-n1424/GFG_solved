class Solution {
  public:
    vector<vector<int>> dp;
    int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& mat,int r,int c){
        int n=mat.size(),m=mat[0].size();
        if(dp[r][c]!=0) return dp[r][c];
        int best=1;
        for(auto dir:directions){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr>=0 && nr<n && nc>=0 && nc<m){
                if(mat[nr][nc]>mat[r][c]){
                    best=max(best,1+dfs(mat,nr,nc));
                }
            }
        }
        return dp[r][c]=best;
    }
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        // code here
        dp.resize(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(matrix,i,j));
            }
        }
        return ans;
    }
};