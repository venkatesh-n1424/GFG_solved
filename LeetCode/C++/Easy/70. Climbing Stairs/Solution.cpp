class Solution {
public:
    vector<int> dp;
    int solve(int n,int i){
        if(i>=n){
            return i==n?1:0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i]=solve(n,i+1)+solve(n,i+2);
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return solve(n,0);
    }
};