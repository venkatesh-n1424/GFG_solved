class Solution {
  public:
    int minSquares(int n, int m) {
        // code here
        int c=0;
        while(m>0&&n>0){
            if(m<n) swap(m,n);
            //Add how many 'n x n' squares can fit into 'm'
            c+=(m/n);
            m%=n;
        }
        return c;
    }
};