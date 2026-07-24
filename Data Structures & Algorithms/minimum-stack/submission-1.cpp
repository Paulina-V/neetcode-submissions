class MinStack {
private:
    stack<int> st;    // all vals
    stack<int> minSt; // min val up to here

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()) { 
            minSt.push(val);
        } else {
            int newMin = min(val, getMin());
            minSt.push(newMin);
        }
    }
    
    void pop() {
        
        minSt.pop();
        
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
       return minSt.top(); 
    }
};
