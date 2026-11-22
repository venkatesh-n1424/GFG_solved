class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        if(n<2) return true;
        for(int i=1;i<n;i++){
            if(s[i]=='a' && s[i-1]=='b') return false;
        }
        return true;
    }
};