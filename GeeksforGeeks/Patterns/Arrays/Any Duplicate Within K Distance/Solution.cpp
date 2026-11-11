class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,vector<int>> mpp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        for(const auto& [key,vec] : mpp){
            int l=vec.size();
            if(l>1){
                for(int i=0;i<l-1;i++){
                    if(abs(vec[i]-vec[i+1])<=k) return true;
                }
            }
        }
        return false;
    }
};