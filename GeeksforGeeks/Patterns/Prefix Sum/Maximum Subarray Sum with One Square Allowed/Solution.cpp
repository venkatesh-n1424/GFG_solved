class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        int max_sum=-1e3,nosq=-1e3,alsq=-1e3;
        for(int& i: arr){
            alsq=max(alsq+i,max(nosq+i*i,i*i));
            nosq=max(nosq+i,i);
            max_sum=max(max_sum,max(nosq,alsq));
        }
        return max_sum;
    }
};