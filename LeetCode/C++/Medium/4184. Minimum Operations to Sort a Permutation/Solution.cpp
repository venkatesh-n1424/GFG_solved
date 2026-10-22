class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int drop_inc=0,drop_dec=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) drop_inc++;
            else drop_dec++;
        }
        if((drop_inc>1 || (drop_inc==1 && nums[n-1]>nums[0])) &&
            (drop_dec>1 || (drop_dec==1 && nums[n-1]<nums[0]))) return -1;
        if(drop_inc==0) return 0;
        if(drop_dec==0) return 1;
        if (drop_inc==1 && nums[n-1]<nums[0]){
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1]) return min(i,n-i+2);
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(nums[i]>nums[i-1]) return min(i,n-i)+1;
            }
        }
        return 0;
    }
};