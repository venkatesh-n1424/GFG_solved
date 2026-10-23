class Solution {
public:
    // vector<vector<int>> ans;
    // void solve(vector<int>& arr,int t,int i,int sum,vector<int> res){
    //     if(i==arr.size() || sum>=t){
    //         if(sum==t) ans.push_back(res);
    //         return;
    //     }
    //     solve(arr,t,i+1,sum,res);
    //     res.emplace_back(arr[i]);
    //     sum+=arr[i];
    //     solve(arr,t,i,sum,res);
    // }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     solve(candidates,target,0,0,vector<int>{});
    //     return ans;
    // }
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int i,int t,vector<int> res){
        if(i==nums.size() || t<=0){
            if(t==0) ans.push_back(res);
            return;
        }
        res.emplace_back(nums[i]);
        solve(nums,i,t-nums[i],res);
        res.pop_back();
        solve(nums,i+1,t,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        solve(nums,0,target,vector<int>{});
        return ans;
    }
};