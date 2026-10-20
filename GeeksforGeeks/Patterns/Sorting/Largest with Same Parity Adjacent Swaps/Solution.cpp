class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0;
        while(i<n){
            int j=i;
            while(i+1<n && arr[i]%2==arr[i+1]%2){
                i++;
            }
            //j->starting of subgroup
            //i->ending of subgroup
            sort(arr.begin()+j,arr.begin()+i+1,greater<int>());
            i++;
        }
        return arr;
    }
};