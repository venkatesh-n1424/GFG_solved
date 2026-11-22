class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        int ans=0,sum=0,n=arr.size();
        for(int i=0;i<n;i++){
            sum=((sum+arr[i])%k+k)%k;
            if(mpp.find(sum)!=mpp.end()) ans=max(ans,i-mpp[sum]);
            else mpp[sum]=i;
        }
        return ans;
    }
};