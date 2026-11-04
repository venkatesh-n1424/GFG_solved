class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        //brute TC-O(n^2)
        int res=0;
        int n=arr.size();
        // for(int i=0;i<n;i++){
        //     int cxor=0;
        //     for(int j=i;j<n;j++){
        //         cxor^=arr[j];
        //         res^=cxor;
        //     }
            
        // }
        // return res;
        //optimal TC-O(n)
        //take count of each ele in how many subarrays it will be that is start*end
        for(int i=0;i<n;i++){
            int start=i+1,end=n-i;
            if((start*end)&1) res^=arr[i];
        }
        return res;
    }
};