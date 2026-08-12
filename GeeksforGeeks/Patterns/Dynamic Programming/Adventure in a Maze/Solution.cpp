class Solution {
  public:
    vector<vector<int>> dp1,dp2;
    int mod=1e9+7;
    int memo1(int i,int j,int n,vector<vector<int>>& grid){
        if(i==n-1 && j==n-1) return 1;
        if(i>=n || j>=n) return 0;
        if(dp1[i][j]!=-1) return dp1[i][j];
        int ans=0;
        if(grid[i][j]==1){
            ans=(ans+memo1(i,j+1,n,grid))%mod;
        }
        else if(grid[i][j]==2){
            ans=(ans+memo1(i+1,j,n,grid))%mod;
        }
        else {
            ans=(ans+memo1(i,j+1,n,grid))%mod;
            ans=(ans+memo1(i+1,j,n,grid))%mod;
        }
        return dp1[i][j]=ans;
    }
    int memo2(int i,int j,int n,vector<vector<int>>& grid){
        if(i==n-1 && j==n-1) return grid[i][j];
        if(i>=n || j>=n) return INT_MIN;
        if(dp2[i][j]!=-1) return dp2[i][j];
        int ans=INT_MIN;
        if(grid[i][j]==1){
            ans=1+memo2(i,j+1,n,grid);
        }
        else if(grid[i][j]==2){
            ans=2+memo2(i+1,j,n,grid);
        }
        else {
            ans=3+max(memo2(i,j+1,n,grid),memo2(i+1,j,n,grid));
        }
        return dp2[i][j]=ans;
    }
    vector<int> findWays(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        dp1.resize(n,vector<int>(n,-1));
        dp2.resize(n,vector<int>(n,-1));
        return vector<int>{memo1(0,0,n,grid),max(0,memo2(0,0,n,grid))};
    }
};