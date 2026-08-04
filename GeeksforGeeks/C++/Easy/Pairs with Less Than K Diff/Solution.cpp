class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        if(k==0) return 0;
        int n=arr.size();
        int l=0,r=1,c=0;
        sort(arr.begin(),arr.end());
        while(l<n){
            if(l==r){
                r=l+1;
            }
            while(r<n && arr[r]-arr[l]<k){
                r++;
            }
            c+=(r-l-1);
            l++;
        }
        return c;
    }
};