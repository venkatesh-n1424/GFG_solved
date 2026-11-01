class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        reverse(digits.begin(),digits.end());
        int i=0;
        while(i<n){
            int sum=digits[i]+1;
            if(sum>9){
                digits[i]=0;
            }
            else{
                digits[i]=sum;
                break;
            }
            i++;
        }
        if(i==n) digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};