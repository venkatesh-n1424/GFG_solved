class MinStack {
public:
    //TC-O(1)
    //SC_O(N)
    int mod=1e+7;
    stack<int> st;
    int min_ele=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            min_ele=value;
            st.push(value);
        }
        else{
            if(value>min_ele) st.push(value);
            else{
                st.push((long)(2*value)%mod-min_ele);
                min_ele=value;
            }
        }
    }
    
    void pop() {
        int n=st.top();
        st.pop();
        if(n<min_ele){
            min_ele=2*min_ele-n;
        }
    }
    
    int top() {
        int n=st.top();
        if(n>min_ele) return n;
        return min_ele;
    }
    
    int getMin() {
        return min_ele;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */