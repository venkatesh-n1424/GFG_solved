class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int row,int col,vector<vector<int>>& mat,int n){
        if(row==n-1) return mat[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int best=0;
        for(int nextcol=0;nextcol<n;nextcol++){
            if(nextcol!=col){
                best=max(best,solve(row+1,nextcol,mat,n));
            }
        }
        return dp[row][col]=best+mat[row][col];
    }
    int zigzagSequence(vector<vector<int>>& mat) {
        int n=mat.size();
        dp.resize(n,vector<int>(n,-1));
        int ans=0;
        for(int col=0;col<n;col++){
            ans=max(ans,solve(0,col,mat,n));
        }
        return ans;
    }
};