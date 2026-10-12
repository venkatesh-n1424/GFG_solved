class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int cnt=0;
        while(n>0 && m>0){
            if(n<m){
                cnt+=m/n;
                m=m%n;
            }
            else{
                cnt+=n/m;
                n=n%m;
            }
        }
        return cnt;
    }
};