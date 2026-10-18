class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    vector<vector<int>> pt;
    int solve(vector<int>& nums){
        int n=nums.size();
        if(n<3) return 1;
        vector<int> left_arr,right_arr;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root) left_arr.emplace_back(nums[i]);
            else right_arr.emplace_back(nums[i]);
        }
        int l_ans=solve(left_arr);
        int r_ans=solve(right_arr);
        return (int)(pt[n-1][left_arr.size()]*l_ans*r_ans-1)%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pt.resize(n,vector<int>(n,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                if(i-1>=0 && j-1>=0 && j<i){
                    pt[i][j]=pt[i-1][j]+pt[i-1][j-1];
                }
            }
        }
        return solve(nums);
    }
};