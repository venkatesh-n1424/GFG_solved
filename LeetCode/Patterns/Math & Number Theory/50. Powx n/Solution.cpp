class Solution {
public:
    double pow(double a,long b){
        if(b==0) return 1.0;
        double ans=pow(a,b/2);
        ans*=ans;
        if(b%2==1) ans*=a;
        return ans;
    }
    double myPow(double x, int n) {
        long nn=n;
        if(n>=0) return pow(x,nn);
        return 1.0/pow(x,-1*nn);
    }
};