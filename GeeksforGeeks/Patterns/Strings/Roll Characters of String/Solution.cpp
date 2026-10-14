class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n=s.size();
        vector<int> diff(n+1,0);
        for(int& x:roll){
            diff[0]++;
            diff[x]--;
        }
        for(int i=1;i<=n;i++){
            diff[i]=diff[i]+diff[i-1];
        }
        for(int i=0;i<n;i++){
            int cur=s[i]-'a';
            int up=(cur+diff[i])%26;
            s[i]='a'+up;
        }
        return s;
    }
};
