class Solution {
public:
    int climbStairs(int n) {
        if  (n==0 || n==1) return 1;
        if (n==2) return 2;
        
        int solArray[n+1];
        solArray[0] = 1;
        solArray[1] = 1;
        solArray[2] = 2;
        
        for (int i=3;i<=n;i++){
            solArray[i] = solArray[i-1] + solArray[i-2];
        }
        
        return solArray[n];
    }
};