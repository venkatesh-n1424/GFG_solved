class Solution {
public:
    int n;
    unordered_set<string> st;
    int dp[2001];

    void solve(int i, string temp, string &s) {
        if(i == n){
            if(temp.size())
                st.insert(temp);
            return;
        }

        solve(i+1, temp+s[i], s);
        solve(i+1, temp, s);
    }

    int distinctSubseqII(string s) {
        n = s.size();
        solve(0, "", s);
        return st.size();
    }
};