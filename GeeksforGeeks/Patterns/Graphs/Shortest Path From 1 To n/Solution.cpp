class Solution {
  public:
    // int solve(int n,int i,int c){
    //     if(i>n) return INT_MAX;
    //     if(i==n) return c;
    //     int left=solve(n,i+1,c+1);
    //     int right=solve(n,i*3,c+1);
    //     return min(left,right);
    // }
    // vector<int> dp;
    // int solve(int n,int i){
    //     if(i==n) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int left=1+solve(n,i+1);
    //     int right=INT_MAX;
    //     if(i*3<=n) 
    //      right=1+solve(n,i*3);
    //     return dp[i] = min(left,right);
    // }
    int minimumStep(int n) {
        // code here
        // brute TC-O(2^n) SC-O(n)
        // return solve(n,1,0);
        //memoization Tc-O(n) Sc-(n)
        // dp.resize(n+1,-1);
        // return solve(n,1);
        int cnt=0;
        while(n>1){
            if(n%3==0 && n/3>=1) n/=3;
            else n--;
            cnt++;
        }
        return cnt;
    }
};