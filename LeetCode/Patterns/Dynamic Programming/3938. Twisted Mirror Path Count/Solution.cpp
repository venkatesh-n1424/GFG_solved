class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        //Tc-O(mn) Sc-O(mn)
        int mod=1e9+7;
        int m=grid.size(),n=grid[0].size();
        vector<vector<pair<int,int>>> dp(m,vector<pair<int,int>>(n,{0,0}));
        //dp[i][j].first=from left
        //dp[i][j].second=from top
        for(int i=1;i<m;i++){
            dp[i][0]={0,1};
            if(grid[i][0]==1) break;
        }
        for(int i=1;i<n;i++){
            dp[0][i]={1,0};
            if(grid[0][i]==1) break;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                    if(grid[i-1][j]==1){
                        dp[i][j].second=dp[i-1][j].first;
                    }
                    else dp[i][j].second=(dp[i-1][j].first+dp[i-1][j].second)%mod;
                    if(grid[i][j-1]==1){
                        dp[i][j].first=dp[i][j-1].second;
                    }
                    else dp[i][j].first=(dp[i][j-1].first+dp[i][j-1].second)%mod;
            }
        }
        return (dp[m-1][n-1].first+dp[m-1][n-1].second)%mod;
    }
};