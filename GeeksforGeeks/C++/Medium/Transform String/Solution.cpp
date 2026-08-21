class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        int n = s1.size();
        if(n!= s2.size()){
            return -1;
        }

        map<char,int> mpp;
        for(char c:s1){
            mpp[c]++;
        }
        for(char c:s2){
            mpp[c]--;
        }
        for(auto pair:mpp){
            if(pair.second != 0){
                return -1;
            }
        }

        int i = n-1;
        int j = n-1;

        while(i >= 0 && j >= 0){
            if(s1[i] == s2[j]){
                i--;
                j--;
            }else{
                i--;
            }
        }
        return j+1;
    }
};
