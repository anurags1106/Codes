class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int minVal = abs(target-nums[0]-nums[1]-nums[2]);
        int retVal = nums[0]+nums[1]+nums[2];
        for (int i=0; i<nums.size()-2; i++) {
            
            int start = i+1;
            int end = nums.size()-1;
            int val = target-nums[i];
            while (start < end) {
                if (nums[start]+nums[end] < val) {
                    if (abs(val-nums[start]-nums[end]) < minVal) {
                        retVal = nums[start]+nums[end]+nums[i];
                        minVal = abs(val-nums[start]-nums[end]);
                    }
                    
                    start++;
                }
                else if (nums[start]+nums[end] > val) {
                    if (abs(val-nums[start]-nums[end]) < minVal) {
                        retVal = nums[start]+nums[end]+nums[i];
                        minVal = abs(val-nums[start]-nums[end]);
                    }
                    end--;
                }
                else {
                    return target;
                }
            }
        }
        
        return retVal;
    }
};