class Solution {
public:
    int mod=1e9+7;
    long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    // Since nCr(n, r) == nCr(n, n - r), take the smaller r for speed
    if (r > n - r) {
        r = n - r;
    }
    
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans *= (n - r + i);
        ans /= i;
    }
    return ans;
}
    int numberOfSets(int n, int k) {
        int res = nCr(n+k-1,k*2)%mod;
        return res;
    }
};