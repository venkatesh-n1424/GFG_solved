class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mpp;
        for(auto& vec:knowledge) mpp[vec[0]]=vec[1];
        bool start=false;
        string cur="",res="";
        for(char& c:s){
            if(c=='('){
                start=true;
            }
            else if(c==')'){
                 start=false;
                 if(mpp.find(cur)!=mpp.end()) res+=mpp[cur];
                 else res+='?';
                 cur="";
            }
            else if(start){
                cur+=c;
            }
            else res+=c;
        }
        return res;
    }
};