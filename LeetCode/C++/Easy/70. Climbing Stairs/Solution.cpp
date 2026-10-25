

class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2) return n;
        int a=1,b=2,r;
        for(int i=3;i<=n;i++){
            r=a+b;
            a=b;
            b=r;
        }
        return r;
    }
};