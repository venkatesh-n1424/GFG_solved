class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //brute
        int m=grid.size(),n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    bool find=true;
                    for(int k=0;k<n;k++){
                        if(k!=j && grid[i][k]){
                            cnt++;
                            find=false;
                            break;
                        }
                    }
                    if(find){
                        for(int k=0;k<m;k++){
                            if(k!=i && grid[k][j]){
                                cnt++;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};