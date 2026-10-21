class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int>& arr,int t,int i,int sum,vector<int> res){
        if(i==arr.size() || sum>=t){
            sort(res.begin(),res.end());
            if(sum==t) ans.insert(res);
            return;
        }
        solve(arr,t,i+1,sum,res);
        res.emplace_back(arr[i]);
        sum+=arr[i];
        solve(arr,t,i+1,sum,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        solve(candidates,target,0,0,vector<int>{});
        vector<vector<int>> res;
        for(auto& val:ans) res.push_back(val);
        return res;
    }
};