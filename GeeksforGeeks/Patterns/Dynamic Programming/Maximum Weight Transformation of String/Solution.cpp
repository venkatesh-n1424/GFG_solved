class Solution {
  public:
    vector<int> dp;
    int solve(int i,string& s){
        if(i>=s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int wt1=1+solve(i+1,s);
        int wt2=0;
        if(i+1<s.size()) {
            if(s[i]!=s[i+1]) wt2=4+solve(i+2,s);
            else wt2=3+solve(i+2,s);
        }
        return dp[i] = max(wt1,wt2);
    }
    int getMaxWeight(string &s) {
        // code here
        dp.resize(s.size()+1,-1);
        return solve(0,s);
    }
};
