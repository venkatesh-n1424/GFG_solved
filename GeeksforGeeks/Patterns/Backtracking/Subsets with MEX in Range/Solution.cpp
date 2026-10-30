class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        // code here
        long long mod=1e9+7;
        int n=arr.size();
        vector<int> freq(n+1,0);
        for(int x:arr) freq[x]++;
        vector<long long> power(n+1,1);
        for(int i=1;i<=n;i++) power[i]=(power[i-1]*2)%mod;
        long long ans=0,prefix=1;
        int rem=n;
        for(int k=0;k<=r;k++){
            rem-=freq[k];
            long long ways=(prefix*power[rem])%mod;
            if(k>=l) ans=(ans+ways)%mod;
            prefix=(prefix*(power[freq[k]]-1+mod))%mod;
        }
        return (int)ans;
    }
};
