class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push to the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket
            else {
                // If stack is empty, there's no matching opening bracket
                if (st.empty()) return false;
                
                char top = st.top();
                
                // Check if the lid matches the most recent container
                if ((c == ')' && top == '(') || 
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')) {
                    st.pop(); // Close it successfully
                } else {
                    return false; // Shapes don't match
                }
            }
        }
        
        // If stack is empty, all brackets were matched. Otherwise, some are left open.
        return st.empty();
    }
};
