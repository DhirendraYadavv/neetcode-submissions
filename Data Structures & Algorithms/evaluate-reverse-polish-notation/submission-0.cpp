#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;
        
        for (const string& token : tokens) {
            // Check if the current token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                
                // POP ORDER MATTERS!
                // The first item popped is the right operand.
                // The second item popped is the left operand.
                int right_operand = st.top();
                st.pop();
                
                int left_operand = st.top();
                st.pop();
                
                // Execute the math and push the result back onto the stack
                if (token == "+") {
                    st.push(left_operand + right_operand);
                } else if (token == "-") {
                    st.push(left_operand - right_operand);
                } else if (token == "*") {
                    st.push(left_operand * right_operand);
                } else if (token == "/") {
                    // C++ integer division naturally truncates toward zero 
                    st.push(left_operand / right_operand); 
                }
            } else {
                // It's a number. Convert the string to an integer and push it.
                st.push(std::stoi(token));
            }
        }
        
        // The final surviving number in the stack is the total evaluated result.
        return st.top();
    }
};