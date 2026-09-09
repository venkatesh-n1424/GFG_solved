class Solution {
public:
    long long countCommas(long long n) {
        long long res=0;
        for(int c=1;c<6;c++){
            long long commas = n-(pow(1000,c)-1);
            res+=max(0LL,commas);
        }
        return res;
    }
};