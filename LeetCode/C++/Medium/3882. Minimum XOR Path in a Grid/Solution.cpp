class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<set<int>>> dp(m,vector<set<int>>(n));
        dp[0][0].insert(grid[0][0]);
        
    }
};