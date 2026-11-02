class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid_ele=nums[n/2];
        int res=0;
        for(int& i: nums){
            res+=abs(i-mid_ele);
        }
        return res;
    }
};