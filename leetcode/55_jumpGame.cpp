class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int curMax = -1;
        for (int i=0; i<nums.size(); i++) {
            if (i+nums[i] > curMax) curMax = i+nums[i];
            if (curMax <= i) return false;
            if (curMax >= nums.size()-1) return true;
        }
        
        return false;
    }
};