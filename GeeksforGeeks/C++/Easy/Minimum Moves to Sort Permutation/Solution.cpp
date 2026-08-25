class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> pos(n+1);
        for(int i=0;i<n;i++){
            pos[arr[i]]=i;
        }
        int curlen=1,maxlen=1;
        for(int val=2;val<=n;val++){
            if(pos[val]>pos[val-1]) curlen++;
            else curlen=1;
            maxlen=max(maxlen,curlen);
        }
        return n-maxlen;
    }
};