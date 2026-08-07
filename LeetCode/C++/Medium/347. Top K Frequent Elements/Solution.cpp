class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(auto i:nums) mpp[i]++;
        vector<pair<int,int>> vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[](const auto& a,const auto& b){
            return a.second>b.second;
        });
        vector<int> res;
        while(k--){
            res.emplace_back(vec[k].first);
        }
        return res;
    }
};