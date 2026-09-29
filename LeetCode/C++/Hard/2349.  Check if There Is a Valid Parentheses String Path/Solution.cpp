class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        function<bool(int,int,int)> dp = [&](int i,int j,int b){
            if(i==m-1 && j==n-1) return b==0;
            if(b<0) return false;
            if(i+1<m && dp(i+1,j,grid[i+1][j]=='('?b+1:b-1) ) return true;
            if(j+1<n && dp(i,j+1,grid[i][j+1]=='('?b+1:b-1) ) return true;
            return false;
        };
        return dp(0,0,grid[0][0]=='('?1:-1);
    }
};