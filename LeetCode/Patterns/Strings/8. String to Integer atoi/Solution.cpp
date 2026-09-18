class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size(),sign=1,res=0;
        while(i<n && s[i]==' ') i++;
        if(i<n && (s[i]=='-'||s[i]=='+')) {
            if(s[i]=='-')
            sign=-1;
            i++;
        }
        while(i<n){
            if(s[i]>='0'&& s[i]<='9'){
                int digit = s[i] - '0';
        if (res > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        res = res * 10 + digit;
        i++;
            }
            else break;

        }

        return res*sign;
    }
};