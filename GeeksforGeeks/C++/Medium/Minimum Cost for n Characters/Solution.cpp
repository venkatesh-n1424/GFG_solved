class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        vector<int> dp(n+1);
        dp[1] = i;
        for(int x=2;x<=n;x++){
            //opt-1
            dp[x] = dp[x-1] + i;
            //opt2-floor(x/2);
            int k1=x/2;
            int cost1 = dp[k1]+c;
            if(2*k1<x) cost1+=(x-2*k1)*i;
            else cost1+=(2*k1-x)*d;
            dp[x]=min(cost1,dp[x]);
            //opt3-ceil
            int k2=(x+1)/2;
            int cost2=dp[k2]+c;
            if(2*k2<x) cost2+=(x-2*k2)*i;
            else cost2+=(2*k2-x)*d;
            dp[x]=min(cost2,dp[x]);
        }
        return dp[n];
    }
};
