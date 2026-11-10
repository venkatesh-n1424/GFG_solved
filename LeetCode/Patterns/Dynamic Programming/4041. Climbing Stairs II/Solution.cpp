class Solution {
public:
    vector<int> dp;
    int solve(int i,int n,vector<int>& costs){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int j=i+1;
        int cost;
        if(j<=n)
        cost=costs[j-1]+1+solve(j,n,costs);
        j=i+2;
        if(j<=n)
        cost=min(cost,costs[j-1]+4+solve(j,n,costs));
        j=i+3;
        if(j<=n)
        cost=min(cost,costs[j-1]+9+solve(j,n,costs));
        return dp[i]=cost;
    }
    int climbStairs(int n, vector<int>& costs) {
        dp.resize(n+1,-1);
        return solve(0,n,costs);
    }
};