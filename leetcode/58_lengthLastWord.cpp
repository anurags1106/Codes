class Solution {
public:
    int lengthOfLastWord(string s) {
        int retVal=0;
        int currVal=0;
        int last = s.size()-1;
        while (last>=0 && s[last]==' ') last--;
        if (last < 0) return 0;
        for (int i=0; i<=last; i++) {
            if (s[i]==' ') {
                retVal = currVal;
                currVal = 0;
            } else {
                currVal++;
            }
        }
        retVal = currVal;
        return retVal;
    }
};