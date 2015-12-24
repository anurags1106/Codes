class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> myStack;
        for (int i=0; i<s.size();i++) {
            if (myStack.empty()) {
                myStack.push(i);
            } else {
                if (s[i] == ')') {
                    if (s[myStack.top()] == '(') {
                        myStack.pop();
                        int prevVal = myStack.empty()?-1:myStack.top();
                        if ((i-prevVal) > maxLen) maxLen = i-prevVal;
                    } else myStack.push(i);
                } else myStack.push(i);
            }
        }
        
        return maxLen;
    }
};