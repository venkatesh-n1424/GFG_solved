class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans;
        //brute
        /*
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]) c++;
            }
            if(c==1) {
                ans=nums[i];
                break;
            }
        }
        */
        //Better : hashing
        map<long long,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second==1) {
                ans=it.second;
                break;
            }
        }
        return ans;
    }
};