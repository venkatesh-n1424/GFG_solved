class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        //Brute 
        /*
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target) {
                    sol.emplace_back(i);
                     sol.emplace_back(j);
                     break;
                }
            }
        }*/
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int rem=target-a;
            if(mpp.find(rem)!=mpp.end()){
                sol.emplace_back(i);
                sol.emplace_back(mpp[rem]);
                break;
            }
            mpp[a]=i;
        }
        return sol;
    }
};