class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=1;
        while(j<n){
            if(arr[j]<arr[j-1]) break;
            j++;
        }
        if(j==n) return;
        int n1=j;
        vector<int> ans(n);
        int k=0;
        while(i<n1 && j<n){
            if(arr[i]<=arr[j]) ans[k++]=arr[i++];
            else ans[k++]=arr[j++];
        }
        while(i<n1){
            ans[k++]=arr[i++];
        }
        while(j<n) ans[k++]=arr[j++];
        arr=ans;
    }
};