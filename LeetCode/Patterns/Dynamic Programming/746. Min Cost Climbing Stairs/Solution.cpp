class Solution {
public:
    vector<int> dp;
    int solve(int i,vector<int>& arr,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int cost=arr[i];
        cost+=min(solve(i+1,arr,n),solve(i+2,arr,n));
        return dp[i]=cost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n+1,-1);
        return min(solve(0,cost,n),solve(1,cost,n));
    }
};