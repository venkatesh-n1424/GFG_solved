class Solution {
  public:
    int maxValue(int n) {
        // code here
        for(int i=31;i>=2;i--){
            if(n&1<<i && n&1<<(i-1) && n&1<<(i-2)) n=n& ~(1<<(i-2));
        }
        return n;
    }
};