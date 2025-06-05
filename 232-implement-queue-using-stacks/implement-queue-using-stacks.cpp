class MyQueue {
public:
    stack<int> st;
    
    MyQueue() {
    }
    
    void push(int x) {
        stack<int> gt;
        // Move everything to temporary stack
        while (!st.empty()) {
            gt.push(st.top());
            st.pop();
        }
        // Push the new element
        st.push(x);
        // Move everything back to main stack
        while (!gt.empty()) {
            st.push(gt.top());
            gt.pop();
        }
    }
    
    int pop() {
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};