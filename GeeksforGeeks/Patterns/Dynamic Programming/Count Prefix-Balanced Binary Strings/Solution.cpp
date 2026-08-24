class Solution {
  public:
    //vector<vector<int>> dp;
    int mod=1e9+7;
    // int fun(int n,int i,int bal){
    //     if(i==n){
    //         if(bal==0) return 1;
    //         return 0;
    //     }
    //     if(bal<0) return 0;
    //     if(dp[i][bal]!=-1) return dp[i][bal];
    //     return dp[i][bal]=(fun(n,i+1,bal+1)+fun(n,i+1,bal-1))%mod;
    // }
    long power(long b,long e){
        long res=1;
        while(e>0){
            if((e&1)==1){
                res=res*b%mod;
            }
            b=b*b%mod;
            e>>=1;
        }
        return res;
    }
    long MODI(long val){
        return power(val,mod-2);
    }
    int prefixStrings(int n) {
        // code here
        //brute
        // if(n==1) return 1;
        // dp.resize(2*n,vector<int>(2*n,-1));
        // return fun(2*n,0,0)%mod;
        //optimal
        vector<long> fact(2*n+1);
        fact[0]=1;
        for(int i=1;i<=2*n;i++){
            fact[i]=fact[i-1]*i%mod;
        }
        long nume = fact[2*n];
        long deno = fact[n]*fact[n]%mod;
        long comb = nume*MODI(deno)%mod;
        long catalan = comb * MODI(n+1)%mod;
        return (int)catalan;
    }
};