class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int u=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[u]){
                nums[++u]=nums[i];
            }
        }
        return u+1;
    }
};