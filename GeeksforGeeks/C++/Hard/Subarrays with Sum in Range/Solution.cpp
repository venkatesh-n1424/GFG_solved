class Solution {
  public:
    int csalek(vector<int>& arr,int k){
        if(k<0) return 0;
        int n=arr.size(),l=0,r=0,c=0;
        int sum=0;
        while(r<n){
            sum+=arr[r];
            while(sum>k){
                sum-=arr[l];
                l++;
            }
            c+=(r-l+1);
            r++;
        }
        return c;
    }
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        int c1=csalek(arr,r),c2=csalek(arr,l-1);
        return c1-c2;
    }
};