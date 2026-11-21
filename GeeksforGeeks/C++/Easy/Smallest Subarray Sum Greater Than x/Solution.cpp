class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int i=0,j=0;
        int sum=0,res=1e5;
        while(j<n){
            sum+=arr[j];
            while(sum>x){
                res=min(res,j-i+1);
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return res==1e5 ? 0: res;
    }
};