class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //brute Tc-O(m*n*(m+n)) Sc-O(1)
        int m=grid.size(),n=grid[0].size();
        int cnt=0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]){
        //             bool find=true;
        //             for(int k=0;k<n;k++){
        //                 if(k!=j && grid[i][k]){
        //                     cnt++;
        //                     find=false;
        //                     break;
        //                 }
        //             }
        //             if(find){
        //                 for(int k=0;k<m;k++){
        //                     if(k!=i && grid[k][j]){
        //                         cnt++;
        //                         break;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        //better Tc-O(n*m) Sc-O(m+n)
        vector<int> rc(m,0),cc(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    rc[i]++;
                    cc[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    if(rc[i]>1) cnt++;
                    else if(cc[j]>1) cnt++;
                }
            }
        }
        return cnt;
    }
};