class Solution {
public:
    bool solve(string& s,int idx,int cnt){
        if(cnt<0) return false;
        if(idx==s.size()) return cnt==0;
        if(s[idx]=='(') return solve(s,idx+1,cnt+1);
        if(s[idx]==')') return solve(s,idx+1,cnt-1);
        return solve(s,idx+1,cnt+1) || solve(s,idx+1,cnt-1) || solve(s,idx+1,cnt);
    }
    bool checkValidString(string s) {
        return solve(s,0,0);
    }
};