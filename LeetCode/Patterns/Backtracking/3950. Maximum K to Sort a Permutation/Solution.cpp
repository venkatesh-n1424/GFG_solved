class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        // int r=0;
        // bool f=false;
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=i){
        //         if(f){
        //             r&=nums[i];
        //         }
        //         else{
        //             r=nums[i];
        //             f=true;
        //         }
        //     }
        // }
        int r=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                r&=nums[i];
            }
        }
        if(r==-1) return 0;
        return r;

    }
};