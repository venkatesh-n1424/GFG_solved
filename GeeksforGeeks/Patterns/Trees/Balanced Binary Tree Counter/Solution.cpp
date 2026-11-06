class Solution {
  public:
    const int mod=1e9+7;
    vector<int> dp;
    long long solve(int h){
        if(h<2) return 1;
        if(dp[h]!=-1) return dp[h];
        long long a=solve(h-1)%mod;
        long long b=solve(h-2)%mod;
        long long c=((2*a)%mod*b+a*a)%mod;
        return dp[h]=c;
    }
    int countBT(int h) {
        // code here
        dp.resize(h+1,-1);
        return solve(h);
    }
};