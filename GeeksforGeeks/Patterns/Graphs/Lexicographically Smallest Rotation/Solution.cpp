class Solution {
  public:
    string lexiString(string &s) {
        // code here
        //brute-TC-O(n^2)
        //rotating right but need to rotate left
        int n=s.size();
        // string res=s;
        // for(int i=1;i<n;i++){
        //     char t=s[n-1];
        //     for(int i=n-1;i>0;i--) s[i]=s[i-1];
        //     s[0]=t;
        //     if(s<=res) res=s;
        // }
        // return res;
        //Booth's Algo TC-O(n)
        string t=s+s;
        int i=0,j=1,k=0;
        while(i<n && j<n && k<n){
            if(t[i+k]==t[j+k]) k++;
            else if(t[i+k]>t[j+k]){
                i=i+k+1;
                if(i==j) i++;
                k=0;
            }
            else{
                j=j+k+1;
                if(i==j) j++;
                k=0;
            }
        }
        return t.substr(min(i,j),n);
    }
};