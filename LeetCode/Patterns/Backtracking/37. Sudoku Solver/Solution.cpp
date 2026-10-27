class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int r,int c,int num){
        for(int i=0;i<9;i++){
            if(board[r][i]==num+'0') return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][c]==num+'0') return false;
        }
        int sr=r-r%3,sc=c-c%3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==num+'0') return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int num=1;num<10;num++){
                        if(isSafe(board,i,j,num)){
                            board[i][j]=num+'0';
                            if(!solve(board)) board[i][j]='.';
                            else return true;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};