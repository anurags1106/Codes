class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return 0;
        
        int curMax = nums[0];
        int runningSum = nums[0];
        
        for (int i=1; i<nums.size(); i++) {
            if (curMax < runningSum) curMax = runningSum;
            if (runningSum <= 0) runningSum = 0;
            runningSum+=nums[i];
        }
        if (curMax < runningSum) curMax = runningSum;
        return curMax;
    }
};