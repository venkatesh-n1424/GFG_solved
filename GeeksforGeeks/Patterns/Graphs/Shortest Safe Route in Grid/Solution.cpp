class Solution {
  public:
    class cell{
        public:
        int row;
        int col;
        int dist;
        cell(int row,int col,int dist){
            this->row=row;
            this->col=col;
            this->dist=dist;
        }
    };
    int shortestPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> unsafe(n,vector<bool>(m,false));
        vector<int> dr = {-1,1,0,0};
        vector<int> dc = {0,0,-1,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    unsafe[i][j]=true;
                    for(int d=0;d<4;d++){
                        int nr = i+dr[d];
                        int nc = j+dc[d];
                        if(nr>=0 && nr<n && nc>=0 && nc<m){
                            unsafe[nr][nc]=true;
                        }
                    }
                }
            }
        }
        queue<cell> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(!unsafe[i][0]){
                q.push(cell(i,0,1));
                visited[i][0]=true;
            }
        }
        while(!q.empty()){
            cell cur = q.front();
            q.pop();
            int row = cur.row;
            int col = cur.col;
            int dist = cur.dist;
            if(col==m-1){
                return dist;
            }
            for(int d=0;d<4;d++){
                int nr=row+dr[d];
                int nc=col+dc[d];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !unsafe[nr][nc] && !visited[nr][nc]){
                    q.push(cell(nr,nc,dist+1));
                    visited[nr][nc]=true;
                }
            }
        }
        return -1;
    }
};