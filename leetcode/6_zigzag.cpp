class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int length = s.size();
        int oddJumper = 2*numRows;
        int evenJumper = -2;
        string result="";
        for(int i=0; i<numRows; i++) {
            oddJumper = oddJumper-2;
            evenJumper = evenJumper+2;
            
            int j = i;
            bool odd = true;
            while (j < length) {
                result.append(1,s[j]);
                if(odd){
                    if(oddJumper) j = j + oddJumper;
                    else j = j + evenJumper;
                    odd = false;
                }
                else {
                    if(evenJumper) j = j + evenJumper;
                    else j = j + oddJumper;
                    odd = true;
                }
            }
        }
        
        return result;
    }
};