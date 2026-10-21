class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int prevsum=0,minsum=INT_MAX;
        for(int& i: arr){
            prevsum+=i;
            prevsum=min(prevsum,i);
            minsum=min(minsum,prevsum);
        }
        return minsum;
    }
};