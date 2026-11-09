class Solution {
  public:
    int getCount(string &s, int k) {
        // code here
        int n=s.size();
        vector<int> cc(26,0);
        cc[s[0]-'a']++;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) cc[s[i]-'a']++;
        }
        int cnt=0;
        for(int& i:cc) if(i==k) cnt++;
        return cnt;
    }
};