class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> retVals;
        
        if (nums.size()<3) return retVals;
        int prev = nums[0]-1;
        for (int i=0; i<nums.size()-3; i++) {
            if (nums[i] == prev) continue;
            prev = nums[i];
            int prevOne = nums[i+1]-1;
            for (int j=i+1; j<nums.size()-2; j++) {
                if (nums[j] == prevOne) continue;
                prevOne = nums[j];
            
                int start = j+1;
                int end = nums.size()-1;
                int val = target-nums[i]-nums[j];
                while (start < end) {
                    if (nums[start]+nums[end] < val) start++;
                    else if (nums[start]+nums[end] > val) end--;
                    else {
                        vector<int> mySet;
                        mySet.push_back(nums[i]);
                        mySet.push_back(nums[j]);
                        mySet.push_back(nums[start]);
                        mySet.push_back(nums[end]);
                        retVals.push_back(mySet);
                        start++;
                        while (start<end && nums[start] == nums[start-1]) start++;
                        end--;
                        while (start<end && nums[end] == nums[end+1]) end--;
                    }
                }
            }
            
        }
        
        
        return retVals;
    }
};