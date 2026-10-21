class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& arr,int t,int i,int sum,vector<int> res){
        if(i==arr.size() || sum>=t){
            if(sum==t) ans.push_back(res);
            return;
        }
        solve(arr,t,i+1,sum,res);
        res.emplace_back(arr[i]);
        sum+=arr[i];
        solve(arr,t,i,sum,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,0,0,vector<int>{});
        return ans;
    }
};