class Solution {
public:
    bool ischar(char c){
        if((c<'A'|| c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9'))
        return false;
        return true;
    }
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<=r){
            if(!ischar(s[l])) l++;
            else if((!ischar(s[r]))) r--;
            else if(tolower(s[l++])!=tolower(s[r--])) return false;
        }
        return true;
    }
};