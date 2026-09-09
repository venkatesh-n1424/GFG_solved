class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        if(n<1e15) return n-1000+1;
        return n-1000+2;
    }
};