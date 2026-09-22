class Solution {
  public:
    bool wordEqual(string str,string& s){
        int m=str.size(),s_m=s.size();
        int j=0,i=0;
        while(i<m){
            if(str[i]==s[j]) i++;
            j++;
            if(j==s_m) break;
        }
        return i==m;
    }
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        string res="";
        sort(d.begin(),d.end(),[](const string& a,const string& b){
            if(a.size()!=b.size()) return a.size()>b.size();
            return a<b;
        });
        for(string& str:d){
            if(wordEqual(str,s)){
                // if(res=="" || res.size()<str.size()
                // || (res.size()==str.size() && str<res)) res=str;
                return str;
            }
        }
        return res;
    }
};