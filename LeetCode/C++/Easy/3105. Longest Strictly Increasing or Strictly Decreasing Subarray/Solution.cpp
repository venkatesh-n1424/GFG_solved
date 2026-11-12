class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si=INT_MIN,sd=INT_MIN;
        int n=nums.size();
        if(n<2) return 1;
        int i=0,j=1;
        while(j<n){
            if(nums[j]>nums[j-1]){
                si=max(si,j-i+1);
            }
            else{
                i=j;
            }
            j++;
        }
        i=0,j=1;
        while(j<n){
            if(nums[j]<nums[j-1]){
                sd=max(sd,j-i+1);
            }
            else{
                i=j;
            }
            j++;
        }
        return si==INT_MIN && sd==INT_MIN? 1: max(si,sd);
    }
};