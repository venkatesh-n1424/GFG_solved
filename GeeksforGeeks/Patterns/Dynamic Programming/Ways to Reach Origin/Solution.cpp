class Solution {
  public:
    int mod=1e9+7;
    int dp[501][501];
    int solve(int x,int y){
        if(x==0 && y==0) return 1;
        if(x<0 || y<0) return 0;
        if(dp[x][y]!=-1) return dp[x][y]%mod;
        return dp[x][y]=(solve(x-1,y)+solve(x,y-1))%mod;
    }
    int ways(int x, int y) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(x,y);
    }
};