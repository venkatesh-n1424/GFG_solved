class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>> val;
       vector<int> res;
       int n=nums.size();
       for(int i=0;i<n;i++) val.push_back({nums[i],i});
       sort(val.begin(),val.end());
       int i=0,j=n-1;
       while(i<j){
        if(val[i].first+val[j].first==target){
            res={val[i].second,val[j].second};
            break;
        }
        else if(val[i].first+val[j].first>target) j--;
        else i++;
       }
       return res;
    }
};