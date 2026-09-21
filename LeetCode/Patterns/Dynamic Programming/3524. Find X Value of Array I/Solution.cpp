class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        //brute
        int n=nums.size();
        vector<long long> res(k,0);
        for(int i=0;i<n;i++){
            l prod=1;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                res[prod%k]++;
            }
        }
        return res;
    }
};