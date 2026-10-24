class Solution {
  public:
    
    bool isPossible(int n, int m, string& s) {
        // code here
        //brute TC-O(m*n) sc-O(1)
        // auto find=[&](int i,int j){
        //      int idx=0;
        //      while(idx<s.size()){
        //          if(s[idx]=='L') j--;
        //          else if(s[idx]=='R') j++;
        //          else if(s[idx]=='D') i++;
        //          else i--;
        //          if(i<0 || j<0 || i>=n || j>=m) return false;
        //          idx++;
        //      }
        //      return true;
        // };
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(find(i,j)) return true;
        //     }
        // }
        // return false;
        //TC-O(|S|)
        int l=0,minc=0,maxc=0,d=0,minr=0,maxr=0;
        for(char& c:s){
            if(c=='L') l--;
            if(c=='R') l++;
            if(c=='U') d--;
            if(c=='D') d++;
            minc=min(minc,l);
            maxc=max(maxc,l);
            minr=min(minr,d);
            maxr=max(maxr,d);
        }
        return (maxc-minc<m && maxr-minr<n);
    }
};