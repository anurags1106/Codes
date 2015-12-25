void permute_r(vector<int> nums, vector<int> currList, vector<vector<int>> &results) {
    if (!nums.size() && currList.size()) {
        results.push_back(currList);
        return;
    }
    
    for (int i=0; i<nums.size();i++) {
        currList.push_back(nums[i]);
        int temp = nums[i];
        nums.erase(nums.begin()+i);
        permute_r(nums,currList,results);
        nums.insert(nums.begin()+i,temp);
        currList.erase(currList.end()-1);
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currList;
        vector<vector<int>> results;
        if(!nums.size()) return results;
        
        permute_r(nums, currList, results);
        
        return results;
    }
};