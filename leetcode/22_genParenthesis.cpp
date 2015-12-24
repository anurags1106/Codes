void generate_r(int open, int close, string curStr, vector<string> &results) {
    if (open == 0 && close == 0) {
        results.push_back(curStr);
        return;
    }
    
    if(close > open) 
    {
        generate_r(open,close-1,curStr.append(1,')'),results);
        curStr.erase(curStr.size()-1,1);
    }
    if (open > 0) generate_r(open-1,close,curStr.append(1,'('),results);
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        
        generate_r(n-1,n,"(",results);
        
        return results;
    }
};