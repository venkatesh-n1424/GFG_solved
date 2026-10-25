class Solution {
  public:
    // int dif(string s){
    //     int al[26]={0};
    //     for(char& c:s) al[c-'a']++;
    //     int maxf=*max_element(al,al+26);
    //     int minf=INT_MAX;
    //     for(int i=0;i<26;i++){
    //         if(al[i]!=0 && al[i]<minf) minf=al[i];
    //     }
    //     return maxf-minf;
    // }
    int beautySum(string &s) {
        // code here
        int n=s.size();
        int sum=0;
        //brute O(n^3)
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         sum+=dif(s.substr(i,j-i+1));
        //     }
        // }
        for(int i=0;i<n;i++){
            int fa[26]={0};
            for(int j=i;j<n;j++){
                int idx=s[j]-'a';
                fa[idx]++;
                int maxf=*max_element(fa,fa+26);
                int minf=INT_MAX;
                for(int k=0;k<26;k++){
                    if(fa[k]!=0 && fa[k]<minf) minf=fa[k];
                }
                sum+=(maxf-minf);
            }
        }
        return sum;
    }
};