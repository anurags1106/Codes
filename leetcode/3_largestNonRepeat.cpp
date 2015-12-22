class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> foundChar(256,false);
        int maxLen = 0;
        int curLen = 0;
        int start = 0;
        for (int i=0; i<s.size(); i++) {
            if(!foundChar[s[i]]) {
                foundChar[s[i]] = true;
                curLen++;
                if (curLen > maxLen) {
                    maxLen = curLen;
                }
            } else {
                while(s[start] != s[i]) {
                    foundChar[s[start]] = false;
                    start++;
                    curLen--;
                }
                start++;
                //curLen--;
            }
        }
        
        return maxLen;
    }
};