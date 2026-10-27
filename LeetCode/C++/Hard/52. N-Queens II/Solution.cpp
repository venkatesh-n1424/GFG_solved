class Solution {
public:
    bool isSafe(vector<vector<bool>>& board,int r,int c,int n){
        for(int i=0;i<r;i++){
            if(board[i][c]) return false;
        }
        int maxleft=min(r,c);
        for(int i=1;i<=maxleft;i++){
            if(board[r-i][c-i]) return false;
        }
        int maxright=min(r,n-c-1);
        for(int i=1;i<=maxright;i++){
            if(board[r-i][c+i]) return false;
        }
        return true;
    }
    int solve(int r,int n,vector<vector<bool>>& board){
        if(r==n) return 1;
        int cnt=0;
        for(int c=0;c<n;c++){
            if(isSafe(board,r,c,n)){
                board[r][c]=true;
                cnt+=solve(r+1,n,board);
                board[r][c]=false;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,false));
        int cnt=solve(0,n,board);
        return cnt;
    }
};