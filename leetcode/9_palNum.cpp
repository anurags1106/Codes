class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        
        double multiplier = 1;
        int temp = x;
        
        while (temp != 0){
            multiplier = multiplier*10;
            temp = temp/10;
        }
        
        int multi1 = multiplier/10;
        temp = x;
        
        while (temp != 0) {
            if (temp < 10) return true;
            if ((x/multi1) != (temp%10)){
                return false;
            }
            x = x%multi1;
            multi1 = multi1/10;
            temp = temp/10;
        }
    }
};