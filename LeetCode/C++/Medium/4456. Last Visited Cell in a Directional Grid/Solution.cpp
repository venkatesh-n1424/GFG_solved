class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int i=0,j=0;
        visited[i][j]=true;
        while(true){
            if(grid[i][j]=='L'){
                if(j-1>=0 && !visited[i][j-1]){
                    j--;
                    visited[i][j]=true;
                }
                else break;
            }
            else if(grid[i][j]=='R'){
                if(j+1<n && !visited[i][j+1]){
                    j++;
                    visited[i][j]=true;
                }
                else break;
            }
            else if(grid[i][j]=='U'){
                if(i-1>=0 && !visited[i-1][j]){
                    i--;
                    visited[i][j]=true;
                }
                else break;
            }
            else {
                if(i+1<m && !visited[i+1][j]){
                    i++;
                    visited[i][j]=true;
                }
                else break;
            }
        }
        return vector<int>{i,j};
    }
};