class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        // code here
        vector<int> arr(n,0);
        int k=updates.size();
        //TC-O(n*k)
        // for(int& j:updates){
        //     for(int i=0;i<n;i++){
        //         if((i+1)>=j) arr[i]++;
        //     }
        // }
        //prefixSum
        //TC-O(n+k), SC-O(1)
        for(int& j:updates) arr[j-1]++;
        for(int i=1;i<n;i++) arr[i]=arr[i]+arr[i-1];
        return arr;
    }
};