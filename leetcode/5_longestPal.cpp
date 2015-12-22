class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        //if (length == 1) return s;
        int start=0,palSize=1;
        /*bool **matrix = new bool*[length];
        for (int i=0; i<length; i++){
            matrix[i] = new bool[length];
        }*/
        bool matrix[1000][1000];
        memset(matrix, 0, sizeof(matrix));
        /*for (int i=0; i<length; i++){
            for(int j=0; j<length; j++){
                if (i == j) matrix[i][j] = true;
                else matrix[i][j] = false;
            }
        }
        
        for (int i=1; i<length; i++){
            if (s[i-1] == s[i]){
                matrix[i-1][i] = true;
                start = i-1;
                palSize = 2;
            }
        }*/
        for (int i=0;i<length;i++) {
            matrix[i][i] = true;
            if ((i<length-1) && (s[i] == s[i+1])) {matrix[i][i+1] = true;start=i;palSize=2;}
        }
        
        for (int i=3; i<=length; i++){
            
            for(int j=0; j<length-i+1;j++){
                if ((s[j] == s[j+i-1]) && matrix[j+1][j+i-2]){
                    start = j;
                    palSize = i;
                    matrix[j][j+i-1] = true;
                }
            }
        }
        
        return s.substr(start,palSize);
    }
};