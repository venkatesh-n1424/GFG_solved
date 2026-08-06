class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int d0=0,dt=0,max_dt=INT_MIN,n=arr.size();
        for(auto i:arr){
            while(i){
                if(i%2) {
                    i--;
                    d0++;
                }
                else {
                    i/=2;
                    dt++;
                }
            }
            max_dt=max(max_dt,dt);
            dt=0;
        }
        return d0+max_dt;
    }
};