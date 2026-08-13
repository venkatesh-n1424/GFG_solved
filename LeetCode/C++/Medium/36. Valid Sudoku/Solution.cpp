class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //brute
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && s.find(board[i][j])==s.end()){
                    s.insert(board[i][j]);
                }
                else if(s.find(board[i][j])!=s.end()) return false;
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(board[j][i]!='.' && s.find(board[j][i])==s.end()){
                    s.insert(board[j][i]);
                }
                else if(s.find(board[j][i])!=s.end()) return false;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                unordered_set<char> s;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]!='.' && s.find(board[x][y])==s.end()){
                    s.insert(board[x][y]);
                }
                else if(s.find(board[x][y])!=s.end()) return false;
                    }
                }
            }
        }
        return true;
    }
};