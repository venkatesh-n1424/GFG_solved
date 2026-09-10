class Solution {
  public:
    int gcd(int a,int b){
        while(b!=0)
        {
            int t=a%b;
            a=b;
            b=t;
        }
        return a;
    }
    int pairCount(int x, int y) {
        // code here
        if(y%x!=0) return 0;
        int n=y/x;
        int c=0;
        for(int p=1;p*p<=n;p++){
            if(n%p==0){
                int q=n/p;
                if(gcd(p,q)==1) c+=2;
            }
        }
        if(n==1) return 1;
        return c;
    }
};