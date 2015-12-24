class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int diff = 0;
        
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == val) diff++;
            else nums[i-diff] = nums[i];
        }
        
        return nums.size()-diff;
    }
};