class Solution {
  public:
    int minFlips(string &s) {
        // code here
        int c1=0,c2=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='0') c1++;
                else c2++;
            }
            else{
                if(s[i]=='0') c2++;
                else c1++;
            }
        }
        return min(c1,c2);
    }
};