class Solution {
  public:
    int mod=1e9+7;
    int countSubsequences(string& s, int n) {
        // code here
        vector<int> dp(n,0);
        for(char&c :s){
            vector<int> newdp=dp;
            int num=c-'0';
            int rem=num%n;
            newdp[rem]=(newdp[rem]+1)%mod;
            for(int r=0;r<n;r++){
                if(dp[r]!=0){
                    int newrem=(r*10+num)%n;
                    newdp[newrem]=(newdp[newrem]+dp[r])%mod;
                }
            }
            dp=newdp;
        }
        return dp[0]%mod;
    }
};