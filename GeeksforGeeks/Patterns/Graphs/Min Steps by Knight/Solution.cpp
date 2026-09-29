class Solution {
  public:
    int dx[8]={1,1,2,2,-1,-1,-2,-2};
    int dy[8]={2,-2,1,-1,2,-2,1,-1};
    bool isSafe(int x,int y,int n,vector<vector<int>>& visited){
        return (x>=1 && x<=n && y>=1 && y<=n && visited[x][y]==0);
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int sx,sy,ex,ey;
        sx=knightPos[0];
        sy=knightPos[1];
        ex=targetPos[0];
        ey=targetPos[1];
        queue<vector<int>> q;
        vector<vector<int>> visited(n+1,vector<int>(n+1,0));
        q.push({sx,sy,0});
        visited[sx][sy]=1;
        while(!q.empty()){
            vector<int> cur=q.front();
            q.pop();
            int x=cur[0];
            int y=cur[1];
            int depth=cur[2];
            if(x==ex && y==ey) return depth;
            for(int k=0;k<8;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(isSafe(nx,ny,n,visited)){
                    q.push({nx,ny,depth+1});
                    visited[nx][ny]=1;
                }
            }
        }
        return -1;
    }
};