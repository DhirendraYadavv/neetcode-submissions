#include <stack>
#include <algorithm>

class MinStack {
private:
    // The stack stores a pair of integers for every level.
    // pair.first  = The actual value being pushed onto the stack
    // pair.second = The absolute minimum value in the stack up to this exact point
    std::stack<std::pair<int, int>> st;

public:
    // Initialize the stack object (the default underlying stack is initially empty)
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            // BASE CASE: The stack has no other numbers.
            // The new value is inherently the minimum value so far.
            // We push the bundle: {Actual Value, Minimum So Far}
            st.push({val, val});
        } else {
            // ONGOING CASE: The stack already contains numbers.
            // We need to figure out what the minimum is at this new top level.
            // We look at the minimum stored right below us (st.top().second).
            int previous_minimum = st.top().second;
            
            // The new minimum is whichever is smaller: the new value, or the old minimum.
            int current_minimum = std::min(val, previous_minimum);
            
            // Push the bundle onto the stack. 
            // Even if 'val' is huge, it just carries a copy of the small 'current_minimum' up with it.
            st.push({val, current_minimum});
        }
    }
    
    void pop() {
        // Because every element is permanently glued to the minimum at its specific level,
        // throwing away the top element naturally throws away its minimum as well.
        // The element revealed underneath perfectly retains the minimum from before.
        st.pop();
    }
    
    int top() {
        // We only want the real value that the user pushed, which is stored in 'first'.
        return st.top().first;
    }
    
    int getMin() {
        // We only want the memorized minimum, which is securely stored in 'second'.
        // No searching required. 
        return st.top().second;
    }
};
