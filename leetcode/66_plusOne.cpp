class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        
        int carry = 0;
        
        for (int i=digits.size()-1; i>=0; i--) {
            digits[i] = digits[i]+carry;
            carry = digits[i]/10;
            if (!carry) break;
            digits[i] = digits[i]%10;
        }
        if(carry) digits.insert(digits.begin(),carry);
        
        return digits;
    }
};