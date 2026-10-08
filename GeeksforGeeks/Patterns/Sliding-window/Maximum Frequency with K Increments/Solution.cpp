class Solution {
  public:
    int maxFrequency(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int l=0,r=0;
        int sum=0,maxFreq=0;
        sort(arr.begin(),arr.end());
        while(r<n){
            sum+=arr[r];
            while((long)arr[r]*(r-l+1)-sum>k){
                sum-=arr[l];
                l++;
            }
            maxFreq=max(maxFreq,r-l+1);
            r++;
        }
        return maxFreq;
    }
};