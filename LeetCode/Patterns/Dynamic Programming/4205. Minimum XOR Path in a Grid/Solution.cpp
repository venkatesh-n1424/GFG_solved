class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<unordered_set<int>>> dp(m,vector<unordered_set<int>>(n));
        dp[0][0].insert(grid[0][0]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int cur=grid[i][j];
                unordered_set<int> cs=dp[i][j];
                if(i==0){
                    for(auto& it:dp[i][j-1]){
                        cs.insert(it^cur);
                    }
                }
                else if(j==0){
                    for(auto& it:dp[i-1][j]){
                        cs.insert(it^cur);
                    }
                }
                else {
                    for(auto& it:dp[i][j-1]){
                        cs.insert(it^cur);
                    }
                    for(auto& it:dp[i-1][j]){
                        cs.insert(it^cur);
                    }
                }
                dp[i][j]=cs;
            }
        }
        // int min_xor=INT_MAX;
        // for(auto& it:dp[m-1][n-1]) min_xor=min(min_xor,it);
        return *min_element(dp[m-1][n-1].begin(),dp[m-1][n-1].end());
    }
};