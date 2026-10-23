class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int>& arr,int t,int i,int sum,vector<int> res){
        if(sum==t){
            ans.insert(res);
            return;
        }
        if(i==arr.size() || sum>t){
            return;
        }
        res.emplace_back(arr[i]);
        solve(arr,t,i+1,sum+arr[i],res);
        res.pop_back();
        solve(arr,t,i+1,sum,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        solve(nums,target,0,0,vector<int>{});
        vector<vector<int>> res;
        for(auto& i:ans) res.push_back(i);
        return res;
    }
};