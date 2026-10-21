class Solution {
public:
     unordered_map<char,string> mpp;
    vector<string> ans;
    void solve(string& digits,int i,string s){
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }
        string t=mpp[digits[i]];
        for(char& c:t){
            solve(digits,i+1,s+c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()<1) return vector<string>{};
        mpp={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        solve(digits,0,"");
        return ans;
    }
};