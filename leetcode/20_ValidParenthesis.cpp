class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        
        for (int i=0; i<s.size(); i++){
            if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) myStack.push(s[i]);
            else {
                if (!myStack.size()) return false;
                char curChar = myStack.top();
                
                if (((s[i] == ')') && (curChar != '(')) || ((s[i] == ']') && (curChar != '[')) || ((s[i] == '}') && (curChar != '{'))) return false;
                myStack.pop();
            }
        }
        
        if (!myStack.size()) return true;
        
        return false;
    }
};