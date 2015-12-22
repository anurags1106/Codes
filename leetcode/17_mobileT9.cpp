void recursiveCall(string digits, vector<string> keyVal, vector<string> &result, string curString) {
    
    if(digits.size() == 0){
        result.push_back(curString);
        return;
    }
    char curChar = digits[0];
    int len;
    if (curChar == '0') len = 1;
    else if (curChar == '7' || curChar == '9') len = 4;
    else len = 3;
    
    string strToProcess = keyVal[curChar-'0'];
    digits.erase(0,1);
    for (int i=0; i<strToProcess.size();i++) {
        curString.append(1,strToProcess[i]);
        recursiveCall(digits,keyVal,result,curString);
        curString.erase(curString.size()-1,1);
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> keyVal;
        vector<string> results;
        
        if (digits.size() == 0) return results;
        //string myStr = " ";
        keyVal.push_back(" ");
        keyVal.push_back("");
        //myStr = "abc";
        keyVal.push_back("abc");
        //myStr = "def";
        keyVal.push_back("def");        
        //myStr = "ghi";
        keyVal.push_back("ghi");
        //myStr = "jkl";
        keyVal.push_back("jkl");
        //myStr = "mno";
        keyVal.push_back("mno");
        //myStr = "pqrs";
        keyVal.push_back("pqrs");
        //myStr = "tuv";
        keyVal.push_back("tuv");
        //myStr = "wxyz";
        keyVal.push_back("wxyz");
        
        recursiveCall(digits,keyVal,results,"");
        
        return results;
    }
};