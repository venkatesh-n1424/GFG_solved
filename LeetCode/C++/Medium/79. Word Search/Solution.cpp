class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    bool find(vector<vector<char>>& board, string word,int i,int j, int idx){
        int m=board.size(),n=board[0].size();
        int l=word.size();
        if(idx>=l) return true;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='@' || board[i][j]!=word[idx])
             return false;
        char t=board[i][j];
        board[i][j]='@';//visited
        for(int k=0;k<4;k++){
            if(find(board,word,i+dr[k],j+dc[k],idx+1)) return true;
        }
        board[i][j]=t;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        int l=word.size();
        if(m*n<l) return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(board,word,i,j,0)) 
                    return true;
            }
        }
        return false;
    }
};