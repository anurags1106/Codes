class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0){
            negative = true;
            x = x*(-1);
        }
        
        double result = 0;
        
        while (x != 0) {
            result = (result*10) + (x%10);
            x = x/10;
        }
        
        if (negative) {
            result = result*(-1);
        }
        
        if (result > INT_MAX || result < INT_MIN) result = 0;
        return result;
    }
};