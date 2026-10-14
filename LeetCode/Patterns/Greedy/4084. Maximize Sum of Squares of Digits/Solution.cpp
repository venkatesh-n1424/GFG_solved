class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int res=0,d=0;
        while(sum){
            res=(long)res*10+min(sum,9);
            d++;
            sum-=min(sum,9);
        }
        if(d>num) return "";
        if(d<num) res=res*pow(10,num-d);
        return to_string(res);
    }
};