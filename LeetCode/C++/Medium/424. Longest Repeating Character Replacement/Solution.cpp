class Solution {
public:
    int characterReplacement(string s, int k) {
        //brute
        int n=s.size(),res=1;
        for(int i=0;i<n;i++){
            vector<int> f(26,0);
            int maxf=0;
            for(int j=i;j<n;j++){
                maxf=max(maxf,++f[s[j]-'A']);
                int changes=(j-i+1)-maxf;
                if(changes<=k){
                    res=max(res,j-i+1);
                }
                else break;
            }
        }
        return res;
    }
};