class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int end = nums.size()-1;
        
        while (end>0 && nums[end] <= nums[end-1]) {
            end--;
        }
        
        if (end == 0) {
            int i = 0;
            int j = nums.size()-1;
            
            while (i<j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        } else {
            sort(nums.begin()+end,nums.end());
            int i = end;
            while (nums[end-1] >= nums[i]) {
                i++;
            }
            
            int temp = nums[end-1];
            nums[end-1] = nums[i];
            nums[i] = temp;
        }
    }
};