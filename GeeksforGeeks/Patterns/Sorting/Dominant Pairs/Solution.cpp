class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        //brute
        int c=0;
        int n=arr.size();
        // for(int i=0;i<n/2;i++){
        //     for(int j=n/2;j<n;j++){
        //         if(arr[i]>=5*arr[j]) c++;
        //     }
        // }
        //2-pointer
        int half=n/2;
        int j=half;
        sort(arr.begin(),arr.begin()+half);
        sort(arr.begin()+half,arr.end());
        for(int i=0;i<half;i++){
            while(j<n && arr[i]>=5*arr[j]) j++;
            c+=(j-half);
        }
        return c;
        
    }
};