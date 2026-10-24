class Solution {
public:
    bool ispal(string str,int s,int e){
        while(s<e){
            if(str[s]!=str[e]) return false;
            s++;
            e--;
        }
        return true;
    }
    void solve(string s,int idx,vector<string>& path,vector<vector<string>>& res){
        if(idx==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(ispal(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(s,0,path,res);
        return res;
    }
};