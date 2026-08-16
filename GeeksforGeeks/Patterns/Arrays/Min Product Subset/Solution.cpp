class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        bool zero=false;
        int ng=0,prod=1;
        int maxng=INT_MIN;
        int minpositive=INT_MAX;
        for(int i:arr){
            if(i==0){
                zero=true;
                continue;
            }
            prod*=i;
            if(i<0){
                ng++;
                maxng=max(maxng,i);
            }
            else minpositive=min(minpositive,i);
        }
        if(ng==0){
            if(zero) return 0;
            return minpositive;
        }
        else if(ng%2==1) return prod;
        return prod/maxng;
    }
};