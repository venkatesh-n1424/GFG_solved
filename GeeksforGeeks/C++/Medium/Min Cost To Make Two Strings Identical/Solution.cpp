class Solution {
  public:
    vector<vector<int>> dp;
    int solve(string &s1,string &s2,int c1,int c2,int i,int j){
        if(i<0) return (j+1)*c2;
        if(j<0) return (i+1)*c1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=solve(s1,s2,c1,c2,i-1,j-1);
        int d1 = c1+solve(s1,s2,c1,c2,i-1,j);
        int d2 = c2+solve(s1,s2,c1,c2,i,j-1);
        return dp[i][j]=min(d1,d2);
        
    }
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        dp.resize(n,vector<int>(m,-1));
        return solve(s1,s2,costS1,costS2,n-1,m-1);
    }
};