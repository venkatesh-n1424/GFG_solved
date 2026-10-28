class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(m));
        
        dp[0][0].insert(grid[0][0]);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;
                
                int curr = grid[i][j];
                unordered_set<int> cs;
                
                if (i == 0) {
                    for (int prev : dp[i][j - 1]) {
                        cs.insert(prev ^ curr);
                    }
                } else if (j == 0) {
                    for (int prev : dp[i - 1][j]) {
                        cs.insert(prev ^ curr);
                    }
                } else {
                    for (int prev : dp[i][j - 1]) {
                        cs.insert(prev ^ curr);
                    }
                    for (int prev : dp[i - 1][j]) {
                        cs.insert(prev ^ curr);
                    }
                }
                
                dp[i][j] = move(cs);
            }
        }
        
        return *min_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
    }
};