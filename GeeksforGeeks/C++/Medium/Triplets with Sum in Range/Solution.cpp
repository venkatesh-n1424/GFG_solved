class Solution {
  public:
  int count(vector<int>& arr,int x){
      int n=arr.size(),c=0;
      for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
            int sum=arr[i]+arr[k]+arr[j];
            if(sum<=x) {
                c+=(k-j);
                j++;
            }
            else k--;
            }
        }
        return c;
  }
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        //brute
        int c=0;
        //int n=arr.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             int sum=arr[i]+arr[k]+arr[j];
        //             if(sum>=l && sum<=r) c++;
        //         }
        //     }
        // }
        //optimal
        sort(arr.begin(),arr.end());
        int c1=count(arr,r);
        int c2=count(arr,l-1);
        c=c1-c2;
        return c;
    }
};