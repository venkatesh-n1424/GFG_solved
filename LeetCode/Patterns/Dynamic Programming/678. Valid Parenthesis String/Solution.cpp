class Solution {
public:
    bool checkValidString(string s) {
        int d=0,cnt=0;
        for(char& c:s){
            if(c=='*'){
                cnt++;
            }
            else if(c==')') d--;
            else d++;
        }
        if(d==0 || d+cnt==0) return true;
        return false;
    }
};