class Solution {
public:
    stack<int> st;
    int op(char s){
        int b=st.top();
        st.pop();
        int a=st.top();
        st.pop();
        if(s=='+') return a+b;
        if(s=='-') return a-b;
        if(s=='*') return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        for(string& s:tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                st.push(op(s[0]));
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};