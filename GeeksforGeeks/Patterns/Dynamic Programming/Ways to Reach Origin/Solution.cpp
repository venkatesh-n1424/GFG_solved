class Solution {
  public:
    int mod=1e9+7;
    // int dp[501][501];
    // int solve(int x,int y){
    //     if(x==0 && y==0) return 1;
    //     if(x<0 || y<0) return 0;
    //     if(dp[x][y]!=-1) return dp[x][y]%mod;
    //     return dp[x][y]=(solve(x-1,y)+solve(x,y-1))%mod;
    // }
    int ways(int x, int y) {
        // code here
        //top-down-dp-Tc-O(xy),sc-O(xy)
        // memset(dp,-1,sizeof(dp));
        // return solve(x,y);
        //bottom-up
        int dp[x+1][y+1];
        for(int i=0;i<=y;i++) dp[0][i]=1;
        for(int i=0;i<=x;i++) dp[i][0]=1;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
        return dp[x][y]%mod;
    }
};