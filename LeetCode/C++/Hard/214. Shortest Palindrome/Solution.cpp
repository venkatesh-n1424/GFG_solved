class Solution {
public:
    string rev(string s){
        int i=0,j=s.size()-1;
        if(j+1<=1) return s;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    vector<int> LPS(string s){
        int n=s.size(),i=0,j=1;
        vector<int> lps(n,0);
        while(j<n){
            if(s[i]==s[j]){
                i++;
                lps[j]=i;
                j++;
            }
            else{
                if(i==0){
                    lps[j]=0;
                    j++;
                }
                else{
                    i=lps[i-1];
                }
            }
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        int n=s.size();
        string srev=rev(s);
        string ns=s+'*'+srev;
        vector<int> lps=LPS(ns);
        string ans= srev.substr(0,n-lps[2*n])+s;
        return ans;
    }
};