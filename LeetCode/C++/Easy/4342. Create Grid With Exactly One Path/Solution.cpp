class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        for(int i=0;i<m;i++){
            string s="";
            s.append(n,'#');
            res.push_back(s);
        }
        for(int i=0;i<n;i++) res[0][i]='.';
        for(int i=0;i<m;i++) res[i][n-1]='.';
        return res;
    }
};