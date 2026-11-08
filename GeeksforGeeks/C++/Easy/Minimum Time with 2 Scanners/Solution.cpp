class Solution {
  public:
    
    int minTime(int n, int s1, int s2) {
        // code here
        int l=0,h=n*max(s1,s2);
        int ans;
        while(l<=h){
            int mid=l+(h-l)/2;
            int docs=mid/s1+mid/s2;
            if(docs>=n){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};