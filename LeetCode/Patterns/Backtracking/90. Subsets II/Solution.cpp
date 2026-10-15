class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ans.push_back(vector<int>{});
        ans.push_back(vector<int>{nums[0]});
        for(int i=1;i<n;i++){
            if(i>0 && nums[i]!=nums[i-1]){
            int s=ans.size();
            for(int j=0;j<s;j++){
                vector<int> list=ans[j];
                list.emplace_back(nums[i]);
                ans.push_back(list);
            }
            }
            else{
                int s=ans.size();
                if(s&1){
                for(int j=s/2+1;j<s;j++){
                    vector<int> list=ans[j];
                    list.emplace_back(nums[i]);
                    ans.push_back(list);
                }
                }
                else{
                    for(int j=s/2;j<s;j++){
                    vector<int> list=ans[j];
                    list.emplace_back(nums[i]);
                    ans.push_back(list);
                }
                }
            }
        }
        return ans;
    }
};