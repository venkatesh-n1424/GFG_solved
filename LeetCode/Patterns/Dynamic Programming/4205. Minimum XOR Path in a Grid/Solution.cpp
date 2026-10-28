class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        function<int(int,int,int)> solve=[&](int i,int j,int x){
            if(i==m-1 && j==n-1) return grid[i][j]^x;
            if(dp[i][j]!=-1) return dp[i][j];
            int op1=INT_MAX,op2=INT_MAX;
            if(j+1<n) op1=solve(i,j+1,grid[i][j]^x);
            if(i+1<m) op2=solve(i+1,j,grid[i][j]^x);
            return dp[i][j]=min(op1,op2);
        };
        return solve(0,0,0);
    }
};