
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> retVals;
        
        if (nums.size()<3) return retVals;
        int prev = nums[0]-1;
        for (int i=0; i<nums.size()-2; i++) {
            if (nums[i] == prev) continue;
            prev = nums[i];
            
            int start = i+1;
            int end = nums.size()-1;
            int val = -nums[i];
            while (start < end) {
                if (nums[start]+nums[end] < val) start++;
                else if (nums[start]+nums[end] > val) end--;
                else {
                    vector<int> mySet;
                    mySet.push_back(nums[i]);
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
        
        
        return retVals;
    }
};