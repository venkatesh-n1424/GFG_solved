class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int r=0,w=0,b=0,n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0) r++;
        //     else if(nums[i]==1) w++;
        //     else b++;
        // }
        // for(int i=0;i<n;i++){
        //     if(r!=0){
        //         nums[i]=0;
        //         r--;
        //     }
        //     else if(w!=0){
        //         nums[i]=1;
        //         w--;
        //     }
        //     else{
        //         nums[i]=2;
        //         b--;
        //     }
        // }
        // optimal
        int l=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[m],nums[l]);
                l++;m++;
            }
            else if(nums[m]==1) m++;
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};