class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n<0) return myPow(1/x,-n);
        if(n&1) return x*myPow(x*x,(n-1)/2);
        return myPow(x*x,n/2);
    }
};