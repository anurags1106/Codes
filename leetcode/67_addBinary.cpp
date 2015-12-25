class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i,j;
        string result = "";
        for (i=a.size()-1,j=b.size()-1;i>=0 && j>=0;i--,j--){
            
            if ((a[i]-'0') && (b[j]-'0')) {
                if (carry) result.append(1,'1');
                else result.append(1,'0');
                carry = 1;
            }
            else {
                int temp = (a[i]-'0') + (b[j] - '0') + carry;
                if (temp == 2){
                    result.append(1,'0');
                    carry = 1;
                }
                else {
                    result.append(1,'0'+temp);
                    carry = 0;
                }
            }
        }
        
        while (i>=0) {
            if (carry && (a[i]-'0')){
                result.append(1,'0');
                carry = 1;
            }
            else {
                result.append(1,carry+a[i]);
                carry = 0;
            }
            i--;
        }
        
        while (j>=0) {
            if (carry && (b[j]-'0')){
                result.append(1,'0');
                carry = 1;
            }
            else {
                result.append(1,carry+b[j]);
                carry = 0;
            }
            j--;
        }
        
        if (carry) result.append(1,'1');
        
        string retVal = "";
        for (i=result.size()-1;i>=0;i--) {
            retVal.append(1,result[i]);
        }
        
        return retVal;
    }
};