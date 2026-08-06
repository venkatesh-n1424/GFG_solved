class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vals;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vals.emplace_back(nums[i],i);
        }
        sort(vals.begin(),vals.end());
        int i=0,j=n-1;
        while(i<j){
            if(vals[i].first+vals[j].first>target) j--;
            else if(vals[i].first+vals[j].first<target) i++;
            else return vector<int> {vals[i].second,vals[j].second};
        }
        return {};
    }
};