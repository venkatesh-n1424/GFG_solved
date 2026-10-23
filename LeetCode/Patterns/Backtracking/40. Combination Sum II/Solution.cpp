class Solution {
public:
    //TC-O(n^n*k*logn)
    // set<vector<int>> ans;
    // void solve(vector<int>& arr,int t,int i,int sum,vector<int> res){
    //     if(sum==t){
    //         ans.insert(res);
    //         return;
    //     }
    //     if(i==arr.size() || sum>t){
    //         return;
    //     }
    //     res.emplace_back(arr[i]);
    //     solve(arr,t,i+1,sum+arr[i],res);
    //     res.pop_back();
    //     solve(arr,t,i+1,sum,res);
    // }
    // vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
    //     sort(nums.begin(),nums.end());
    //     solve(nums,target,0,0,vector<int>{});
    //     vector<vector<int>> res;
    //     for(auto& i:ans) res.push_back(i);
    //     return res;
    // }
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int t,int i,vector<int> res){
        if(i==nums.size() || t<=0){
            if(t==0)
            ans.push_back(res);
            return;
        }
        res.emplace_back(nums[i]);
        solve(nums,t-nums[i],i+1,res);
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]!=nums[j-1]){
                res.pop_back();
                res.emplace_back(nums[j]);
                solve(nums,t-nums[j],j+1,res);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0,vector<int>{});
        return ans;
    }
};