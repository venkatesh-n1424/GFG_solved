class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    int solve(int n,int k,int i){
        if(k==0) return 1;
        if(i>=n) return 0;
        if(dp[k][i]!=-1) return dp[k][i]%mod;
        long long skip = solve(n,k,i+1)%mod;
        long long take=0;
        for(int j=i+1;j<n;j++){
            take=(take+solve(n,k-1,j))%mod;
        }
        return dp[k][i]=(skip+take)%mod;
    }
    int numberOfSets(int n, int k) {
        dp.resize(1001,vector<int>(1001,-1));
        return solve(n,k,0);
    }
};