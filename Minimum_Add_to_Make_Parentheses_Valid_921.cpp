/*The provided C++ code defines a class named `Solution` with a member function `minAddToMakeValid`. This function takes a string `s` as input, which represents a sequence of parentheses (either '(' or ')'). The goal of the function is to determine the minimum number of parentheses that need to be added to make the input string a valid parentheses sequence.

Here's an explanation of how the code works:

1. Initialize a stack (`stack<char> st`) to keep track of open parentheses '(' encountered while iterating through the input string `s`.

2. Iterate through each character of the input string `s` using a `for` loop:
   - For each character `ch` at index `i` in the string:
   - If `ch` is an open parenthesis '(' (i.e., `ch == '('`), push it onto the stack `st`. This represents an unmatched open parenthesis.

   - If `ch` is a closing parenthesis ')' (i.e., `ch == ')'`), we need to check if there is a corresponding open parenthesis on the stack. There are two cases to consider:
     - If the stack is empty (`st.empty()`) or the top element of the stack is not an open parenthesis (i.e., `st.top() != '('`), push the current closing parenthesis onto the stack. This represents an unmatched closing parenthesis that needs to be balanced.

     - If there is a matching open parenthesis on the stack (i.e., `st.top() == '('`), pop the top element from the stack, indicating that the open parenthesis is matched with the current closing parenthesis. This effectively "closes" the matched pair.

3. After iterating through the entire input string, the stack `st` may still contain some unmatched open parentheses. The size of the stack represents the minimum number of closing parentheses needed to balance the input string and make it valid.

4. Finally, return the size of the stack (`st.size()`) as the result, which represents the minimum number of parentheses that need to be added to make the input string `s` a valid parentheses sequence.

In summary, this code uses a stack to keep track of unmatched open parentheses while iterating through the input string. For each encountered closing parenthesis, it attempts to match it with a corresponding open parenthesis on the stack. The size of the remaining stack at the end represents the minimum number of parentheses that need to be added to balance the input string.

***********************Solution**************** */
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch=='(')st.push(ch);
            else{
                if(ch==')' && (st.empty() ||st.top()!='('))st.push(ch);
                else st.pop();
            }
        }
        return st.size();
    }
};
