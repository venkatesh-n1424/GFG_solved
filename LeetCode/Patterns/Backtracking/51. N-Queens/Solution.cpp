class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string>& ans,int r,int c,int n){
        int tr=r,tc=c;
        for(int i=0;i<r;i++){
            if(ans[i][c]=='Q') return false;
        }
        for(int i=0;i<min(r,c);i++){
            tr--;
            tc--;
            if(ans[tr][tc]=='Q') return false;
        }
        tr=r;
        tc=c;
        for(int i=0;i<min(r,n-c-1);i++){
            tr--;
            tc++;
            if(ans[tr][tc]=='Q') return false;
        }
        return true;
    }
    void solve(int r,int n,vector<string>& ans){
        if(r==n){
            res.push_back(ans);
            return;
        }
        for(int c=0;c<n;c++){
            if(isSafe(ans,r,c,n)){
                ans[r][c]='Q';
                solve(r+1,n,ans);
                ans[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans;
        for(int i=0;i<n;i++){
            string s="";
            s.append(n,'.');
            ans.push_back(s);
        }
        solve(0,n,ans);
        return res;
    }
};