class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //brute
        int n=nums.size();
        // int mis;
        // for(int i=0;i<=n;i++){
        //     bool res=false;
        //     for(int j=0;j<n;j++){
        //         if(nums[j]==i) res=true;
        //     }
        //     if(!res) mis=i; 
        // }
        // return mis;
        //better
        // int sum=0;
        // for(int i=0;i<n;i++) sum+=nums[i];
        // int wholesum = n*(n+1)/2;
        // return wholesum-sum;
        //optimal
        int res=0;
        for(int i=1;i<=n;i++) res^=i;
        for(int i=0;i<n;i++) res^=nums[i];
        return res;
    }
};