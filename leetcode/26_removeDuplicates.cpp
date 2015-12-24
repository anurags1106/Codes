class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(!nums.size()) return 0;
        
        int prevVal = nums[0];
        int prevIndex = 0;
        
        for (int i=1; i<nums.size(); i++){
            if (nums[i] == prevVal) continue;
            prevIndex++;
            nums[prevIndex] = nums[i];
            prevVal = nums[i];
        }
        
        return prevIndex+1;
    }
};