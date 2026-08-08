class Solution {
  public:
    int f(int n,vector<int>& dp){
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=0) return dp[n];
        return dp[n]=f(n-1,dp)+(n-1)*f(n-2,dp);
    }
    int countFriendsPairings(int n) {
        // code here
        vector<int> dp(n+1,0);
        return f(n,dp);
    }
};
