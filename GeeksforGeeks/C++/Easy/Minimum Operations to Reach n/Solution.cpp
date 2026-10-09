class Solution {
  public:
    int minOperation(int n) {
        // code here
        int minop=0;
        while(n){
            if(n&1) n--;
            else n>>=1;
            minop++;
        }
        return minop;
    }
};