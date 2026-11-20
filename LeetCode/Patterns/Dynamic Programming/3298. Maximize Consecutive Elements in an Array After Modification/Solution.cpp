class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int findfun(vector<int>& nums,int s,int t){
        int j=lower_bound(nums.begin()+s,nums.end(),t) - nums.begin();
        if(j<n && nums[j]==t){
            return j;
        }
        return -1;
    }
    int solve(int i,int inc,vector<int>& nums){
        if(memo[i][inc]!=-1) return memo[i][inc];
        int cur=nums[i]+inc,len=1;
        int j=findfun(nums,i+1,cur+1);
        if(j!=-1) len=max(len,1+solve(j,0,nums));
        j=findfun(nums,i+1,cur);
        if(j!=-1) len=max(len,1+solve(j,1,nums));
        return memo[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        //TC-O(nlogn) Sc-O(n)
        n=nums.size();
        sort(nums.begin(),nums.end());
        memo.assign(n+1,vector<int>(2,-1));
        int res=1;
        for(int i=0;i<n;i++){
            res=max({res,solve(i,0,nums),solve(i,1,nums)});
        }
        return res;
    }
};