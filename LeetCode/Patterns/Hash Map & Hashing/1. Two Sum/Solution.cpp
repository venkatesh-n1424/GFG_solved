class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //brute
        int n=nums.size();
        // vector<int> res;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums.at(i)+nums.at(j)==target) res = {i,j};
        //     }
        // }
        // return res;
        //optimal
        vector<pair<int,int>> val;
        for(int i=0;i<n;i++) val.emplace_back(nums.at(i),i);
        sort(val.begin(),val.end());
        int i=0,j=n-1;
        while(i<j){
            if(val[i].first+val[j].first>target) j--;
            else if(val[i].first+val[j].first<target) i++;
            else return vector<int> {val[i].second,val[j].second};
        }
        return {};
    }
};