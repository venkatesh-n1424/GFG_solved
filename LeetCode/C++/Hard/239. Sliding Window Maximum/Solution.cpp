class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //brute
        int n=nums.size();
        int i=0,j=k-1;
        vector<int> res;
        while(j<n){
            int max_ele = *max_element(nums.begin()+i,nums.begin()+j+1);
            res.emplace_back(max_ele);
            i++;
            j++;
        }
        return res;
    }
};