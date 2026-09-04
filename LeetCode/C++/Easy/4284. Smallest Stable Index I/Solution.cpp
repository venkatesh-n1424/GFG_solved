class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int index;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int score=(*max_element(nums.begin(),nums.begin()+i+1)-*min_element(nums.begin()+i,nums.end()));
            if(score<=k) return i;
        }
        return -1;
    }
};