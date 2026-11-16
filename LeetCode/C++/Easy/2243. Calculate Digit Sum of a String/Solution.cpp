class Solution {
public:
    
    string digitSum(string s, int k) {
        while(s.size()>k){
            int n=s.size();
            string cur="";
            for(int i=0;i<n;i+=k){
                int sum=0;
                for(int j=i;j<min(i+k,n);j++){
                    sum+=(s[j]-'0');
                }
                cur+=to_string(sum);
            }
            s=cur;
        }
        return s;
    }
};