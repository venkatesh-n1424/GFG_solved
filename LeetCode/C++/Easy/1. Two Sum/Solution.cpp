class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums.at(i)+nums.at(j)==target) res = {i,j};
            }
        }
        return res;
    }
};