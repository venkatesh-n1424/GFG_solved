class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> st;
        int i=0,j=0,n=s.size(),t=k,ans=1;
        while(j<n){
            st.insert(s[j]);
            if(st.size()>1){
                if(t){
                st.erase(s[j]);
                s[j]=s[j-1];
                t--;
                }
                else{
                    ans=max(ans,j-i);
                    i=j-1;
                    st.erase(s[i]);
                    t=k;
                }
            }
            j++;
        }
        return ans=max(ans,j-i);
    }
};