class Solution {
  public:
    int findxor(int n){
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
        return n;
    }
    int findXOR(int l, int r) {
        // code here
        //brtue Tc-O(n=r-l+1)
        // int res=0;
        // for(int i=l;i<=r;i++) res^=i;
        // return res;
        return findxor(r)^findxor(l-1);
    }
};